#include<bits/stdc++.h>
using namespace std;

int res = 0;
string str = " ";

class TrieNode{
    public:
    TrieNode *children[26];
    bool isEndOfWord;
    int value;

    TrieNode(){
        for(int i = 0; i<26; i++){
            children[i] = nullptr;
        }

        isEndOfWord = false;
        value = 0;
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
    nodePtr->value+=1;
    if(nodePtr->value>res){
        res = nodePtr->value;
        str = s;
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
    
    cout<<"Most Frequent Word: "<<str<<endl;
    cout<<"No of times: "<<res<<endl;
}