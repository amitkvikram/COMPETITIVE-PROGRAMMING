#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define sz size()

class TrieNode{
    public:
    TrieNode *children[26];
    bool isEndOfWord;

    TrieNode(){
        for(int i = 0; i<26; i++){
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }

};

void insert(TrieNode &root, string &s){
    TrieNode *nodePtr= &root;

    for(int i = 0; i<s.size(); i++){
        int index= s[i] - 'a';
        if(nodePtr->children[index] == nullptr){
            nodePtr->children[index] = new TrieNode;
        }

        nodePtr = nodePtr->children[index];
    }

    nodePtr->isEndOfWord = true;
}

TrieNode *search(TrieNode &root, string &s, int len){
    TrieNode *nodePtr = nullptr;
    if(len > 0) nodePtr = &root;

    for(int i = 0; i<len; i++){
        int index = s[i] - 'a';
        if(nodePtr->children[index] == nullptr) return nullptr;
        nodePtr = nodePtr->children[index];
    }

    return nodePtr;
}

void print_tree(TrieNode *nodePtr, string &s, int level){
    // cout<<"Printing: ";
    if(nodePtr == nullptr) return;
    if(nodePtr->isEndOfWord == true) cout<<s.substr(0, level)<<endl;
    for(int i = 0; i<26; i++){
        if(nodePtr->children[i] == nullptr) continue;
        s[level] = i + 'a';
        print_tree(nodePtr->children[i], s, level + 1);
    }
}

int main(){
    TrieNode root;
    int n;
    cin>>n;

    string s;
    for(int i = 0; i<n; i++){
        cin>>s;
        insert(root, s);
    }

    int len = 0, null_cnt = 0;
    TrieNode *currPtr = nullptr; 
    s.clear();
    s.resize(10);

    char ch;
    cin>>ch;
    do{
        // cout<<s.substr(0, len)<<endl;
        cout<<"Result: \n";
        if(ch>='a' && ch<='z'){
            cout<<"character found\n";
            s[len] = ch;
            len++;
            if(null_cnt > 0){
                null_cnt++;
                cout<<"No Search Found\n";
            }
            else if(currPtr == nullptr){
                currPtr = search(root, s, len);
                if(currPtr == nullptr){
                    cout<<"No Search Found\n";
                    null_cnt++;
                }
                else print_tree(currPtr, s, len);
            }
            else{
                cout<<"Here\n";
                if(currPtr->children[ch - 'a'] == nullptr){
                    cout<<"No Search Found\n";
                    currPtr = nullptr;
                    null_cnt++;
                }
                else{
                    print_tree(currPtr->children[ch - 'a'], s, len);
                    currPtr = currPtr->children[ch - 'a'];
                }
            }
        }
        else if(ch == '-'){ 
            if(len == 0) break;
            len--;
            if(null_cnt>0) null_cnt--;
            if(null_cnt == 0){
                currPtr = search(root, s, len);
                if(currPtr == nullptr){
                    cout<<"No Search Found\n";
                } 
                print_tree(currPtr, s, len);
            }
        }
        else{
            break;
        }
        cin>>ch;
        cout<<"----------------\n";
    }while(1);
}