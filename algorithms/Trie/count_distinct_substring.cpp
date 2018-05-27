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

void insert(TrieNode &root, string s){
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

void print_substring(TrieNode *nodePtr, string &s, int level){
    if(level> 0 ){
        cout<<s.substr(0, level)<<endl;
    }

    for(int i = 0; i<26; i++){
        if(nodePtr->children[i] == nullptr) continue;
        s[level] = i + 'a';
        print_substring(nodePtr->children[i], s, level+1);
    }
}

int main(){
    TrieNode root;
    string s;
    cin>>s;

    for(int i = 0; i<s.size(); i++){
        insert(root, s.substr(i));
    }

    s.resize(20);
    print_substring(&root,s, 0);

}