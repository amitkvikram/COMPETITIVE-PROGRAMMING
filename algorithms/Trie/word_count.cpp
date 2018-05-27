#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode *children[26];
    bool isEndOfWord;
    TrieNode(){
        for(int i = 0;i<26; i++){
            children[i] = nullptr;
        }

        isEndOfWord = false;
    }
};

void insert(TrieNode *nodePtr, string &s){
    for(int i = 0; i<s.size(); i++){
        int index = s[i] - 'a';
        if(nodePtr->children[index] == nullptr){
            nodePtr->children[index] = new TrieNode;
        }

        nodePtr = nodePtr->children[index];
    }

    nodePtr->isEndOfWord = true;
}

int word_count(TrieNode *nodePtr){
    int cnt = 0;
    if(nodePtr->isEndOfWord == true){
        // cout<<"h\n";
         cnt = 1;
    }

    for(int i = 0; i<26; i++){
        if(nodePtr->children[i] == nullptr) continue;
        cnt+=word_count(nodePtr->children[i]);
    }

    return cnt;
}

int main(){
    TrieNode root;
    int n;
    cin>>n;

    string s;
    for(int i = 0; i<n; i++){
        cin>>s;
        insert(&root, s);
    }

    cout<<word_count(&root)<<endl;
}