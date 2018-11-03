#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

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

TrieNode *search(TrieNode &root, string &s){
    TrieNode *nodePtr = &root;
    for(int i = 0; i<s.size(); i++){
        int index = s[i] - 'a';
        if(nodePtr->children[index] == nullptr) return nullptr;
        nodePtr = nodePtr->children[index];
    }

    return nodePtr;
}

void auto_complete_util(TrieNode *nodePtr, string &s, int level){
    if(nodePtr->isEndOfWord == true){
        cout<<s.substr(0, level)<<endl;
    }

    for(int i = 0; i<26; i++){
        if(nodePtr->children[i] == nullptr) continue;
        s[level] = 'a' + i;
        auto_complete_util(nodePtr->children[i], s, level + 1);
    }

}

void auto_complete(TrieNode &root, string &s){
    TrieNode *currPtr = search(root, s);
    if(currPtr == nullptr){
        cout<<"prefix not found\n";
        return;
    } 
    int level = s.size();
    s.resize(s.size() + 20, '\0');
    auto_complete_util(currPtr, s, level);
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

    cin>>n;   //no of query
    for(int i = 0; i<n; i++){
        cin>>s;
        auto_complete(root, s);
    }
}