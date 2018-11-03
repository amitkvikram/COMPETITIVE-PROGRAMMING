#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode *children[26];
    bool isEndOfWord;
    int numOfChild;

    TrieNode(){
        for(int i = 0; i<26; i++){
            children[i] = nullptr;
        }
        isEndOfWord = false;
        numOfChild = 0;
    }
};

int res = INT_MAX;

void insert(TrieNode *nodePtr, string &s){
    for(int i = 0; i < s.size(); i++){
        int index = s[i] - 'a';
        if(nodePtr->numOfChild>0 && nodePtr->children[index] == nullptr){
            res = min(res, i);
            return;
        }

        if(nodePtr->children[index] == nullptr){
            nodePtr->children[index] = new TrieNode;
            nodePtr->numOfChild++;
        }

        nodePtr = nodePtr->children[index];
    }
    res = min(res, int(s.size()));
}

int main(){
    TrieNode root;
    int n;
    cin>>n;
    string s;
    for(int i =0; i<n;i++){
        cin>>s;
        insert(&root, s);
    }
    cout<<res<<endl;
}
