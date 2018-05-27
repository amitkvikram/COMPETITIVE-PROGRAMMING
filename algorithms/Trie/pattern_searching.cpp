#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class TrieNode{
    public:
    TrieNode *children[26];
    bool isEndOfWord;
    vi index;

    TrieNode(){
        for(int i = 0; i<26; i++){
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

void insert(TrieNode &root, string s, int suffix_index){
    TrieNode *nodePtr = &root;

    for(int i = 0; i<s.size(); i++){
        int index = s[i] - 'a';
        if(nodePtr->children[index] == nullptr){
            nodePtr->children[index] = new TrieNode;
        }
        nodePtr = nodePtr->children[index];
        nodePtr->index.push_back(suffix_index);
    }

    nodePtr->isEndOfWord = true;
}

TrieNode *pattern_search(TrieNode *nodePtr, string &s){
    for(int i = 0; i<s.size(); i++){
        int index = s[i] - 'a';
        if(nodePtr->children[index] == nullptr) return nullptr;
        nodePtr = nodePtr->children[index];
    }
    return nodePtr;
}

int main(){
    TrieNode root;
    string s;
    cin>>s;

    for(int i = 0; i<s.size(); i++){
        insert(root, s.substr(i), i);
    }

    int n;
    cin>>n;
    while(n--){
        cin>>s;
        TrieNode *tempPtr = pattern_search(&root, s);
        if(tempPtr == nullptr){
            cout<<"Pattern Not Found\n";
        }
        else{
            for(int i = 0; i<tempPtr->index.size(); i++){
                cout<<"Pattern found at index "<<tempPtr->index[i]<<endl;
            }
        }
    }
}