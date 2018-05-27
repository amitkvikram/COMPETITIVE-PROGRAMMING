#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    map<char, TrieNode*> children;
    bool isEndOfWord;
    TrieNode(){
        isEndOfWord = false;
    }
};

void insert(TrieNode &root, string &s){
    TrieNode *nodePtr = &root;
    TrieNode *tempPtr;
    map<char, TrieNode*>::iterator it;
    for(int i = 0; i<s.size(); i++){
        it = nodePtr->children.find(s[i]);
        // cout<<s[i]<<endl;
        if(it == nodePtr->children.end()){
            tempPtr = new TrieNode;
            // cout<<s[i]<<" not found\n";
            nodePtr->children.insert(std::pair<char,TrieNode*>(s[i], tempPtr));
            nodePtr = tempPtr;
        }

        else nodePtr = it->second;
    }

    nodePtr->isEndOfWord = true;
}

bool search(TrieNode &root, string &s){
    TrieNode *nodePtr = &root;
    map<char, TrieNode*>::iterator it;

    for(int i = 0; i<s.size(); i++){
        it = nodePtr->children.find(s[i]);
        if(it == nodePtr->children.end()) return false;
        nodePtr = it->second;
    }
    return nodePtr->isEndOfWord;
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

    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>s;
        if(search(root, s)) cout<<"found\n";
        else cout<<"Not Found\n";
    }
}