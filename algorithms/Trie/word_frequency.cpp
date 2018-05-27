#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode *children[26];
    bool isEndOfWord;
    int occurrence;

    TrieNode(){
        for(int i = 0; i<26; i++){
            children[i] = nullptr;
        }

        isEndOfWord = false;
        occurrence = 0;
    }
};

void insert(TrieNode &root, string s){
    TrieNode *nodePtr = &root;

    for(int i = 0; i<s.size(); i++){
        int index = s[i] - 'a';
        if(nodePtr->children[index] == nullptr){
            nodePtr->children[index] = new TrieNode;
        }

        nodePtr = nodePtr->children[index];
    }

    nodePtr->isEndOfWord = true;
    nodePtr->occurrence+=1;
}

int word_freuency(TrieNode &root, string &s){
    TrieNode *nodePtr = &root;

    for(int i = 0; i<s.size(); i++){
        int index = s[i] - 'a';
        if(nodePtr->children[index] == nullptr){
            return 0;
        }
        nodePtr = nodePtr->children[index];
    }

    return nodePtr->occurrence;
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
        cout<<word_freuency(root, s)<<endl;
    }
}
