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

void display(TrieNode &root, TrieNode *nodePtr, string &s, int level){
    if(nodePtr->isEndOfWord == true){
        cout<<s.substr(0, level)<<endl;
    }

    for(int i = 0; i<26; i++){
        if(nodePtr->children[i] == nullptr) continue;
        s[level] = i + 'a';
        display(root, nodePtr->children[i], s, level + 1);
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
    s.clear();
    s.resize(26, '\0');
    display(root, &root, s, 0);
}