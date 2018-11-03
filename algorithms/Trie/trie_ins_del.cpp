#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

    class TrieNode{
        public:
        TrieNode *children[26];
        bool isEndOfWord;
        int numChild = 0;
        TrieNode(){
            cout<<"Constructor Called\n";
            for(int i = 0; i<26; i++){
                children[i] = nullptr;
            }
            isEndOfWord = false;
        }
        ~TrieNode(){
            cout<<"Destructor Called\n";
        }
    };

void insert(TrieNode &root, string &str){
    TrieNode *tempPtr = &root;
    for(int i = 0; i<str.size(); i++){
        int index = str[i] - 'a';
        if(tempPtr->children[index] == nullptr){
            tempPtr->children[index] = new TrieNode;
            tempPtr->numChild++;
        }
        tempPtr = tempPtr->children[index];
    }
    tempPtr->isEndOfWord = true;
}

bool find(TrieNode &root, string &str){
    TrieNode *tempPtr = &root;
    for(int i = 0; i<str.size(); i++){
        int index = str[i] - 'a';
        if(tempPtr->children[index] == nullptr) return false;
        tempPtr = tempPtr->children[index];
    }
    return(tempPtr->isEndOfWord);
}

bool delete_node(TrieNode *node, string &str, int ind){
    int n = str.size();
    if(ind == n){
        if(node->isEndOfWord == true){
            node->isEndOfWord = false;    //if string is prefix of a longer string.
            if(node->numChild == 0){      // if string is complete string.
                delete node;  
                return true;
            }
            return false;
        }
        return false;
    }
    
    if(node->children[str[ind] - 'a'] == nullptr) return false;  //String dosn't exist(Case1).

    else{
        bool check = delete_node(node->children[str[ind] - 'a'], str, ind+1);
        if(check == true){
            if(ind == 0){
                node->children[str[ind] - 'a'] = nullptr;
                return true;
            }
            if(node->numChild == 1 && node->isEndOfWord == false){
                delete node;
                return true;
            }
            else{
                node->children[str[ind] - 'a'] = nullptr;
                return false;
            }
        }
        return false;
    }
}

int main(){
    TrieNode root;
      string s;
    int option = 1;
    do{
        if(option == 1){
            cout<<"Enter Sting to be inserted: ";
            cin>>s;
            insert(root, s);
        }
        else if(option == 2){
            cout<<"Enter String to be searched: ";
            cin>>s;
            if(find(root, s)){
                cout<<"String Found\n";
            }
            else{
                cout<<"Not Found\n";
            }
        }
        else if(option == 3){
            cout<<"Enter String to be deleted\n";
            cin>>s;
            delete_node(&root, s, 0);
        }
        else{
            break;
        }
        cout<<"Enter Option: ";
        cin>>option;
    }while(option == 1 || option == 2 || option == 3);
    return 0;
}