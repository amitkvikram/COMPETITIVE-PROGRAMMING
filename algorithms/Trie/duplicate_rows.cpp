#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode *children[2];
    bool isEndOfWord;

    TrieNode(){
        for(int i = 0; i<2; i++){
            children[i] = nullptr;
        }

        isEndOfWord = false;
    }
};

bool insert(TrieNode &root, vector<int> v){
    TrieNode *nodePtr = &root;

    for(int i = 0; i<v.size(); i++){
        int index = v[i];
        if(nodePtr->children[index] == nullptr){
            nodePtr->children[index] = new TrieNode;
        }

        nodePtr = nodePtr->children[index];
     }

     bool status = nodePtr->isEndOfWord;

     nodePtr->isEndOfWord = true;

     return status;
}

int main(){
    TrieNode root;
    int a;
    int n, m;
    cin>>n>>m;
    vector<int> v(m);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>v[j];
        }

        if(insert(root, v)) cout<<"Duplicate found at row number: "<<i+1<<endl;
    }


}