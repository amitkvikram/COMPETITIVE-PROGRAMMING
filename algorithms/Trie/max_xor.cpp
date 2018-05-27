#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class TrieNode{
    public:
    TrieNode *children[2];

    bool isEndOfWord;
    TrieNode(){
        for(int i = 0; i<2; i++){
            children[i]  = nullptr;
        }
        isEndOfWord = false;
    }
};

void insert(TrieNode &root, int key){
    TrieNode *nodePtr = &root;

    for(int i = 31; i>=0; i--){
        bool current_bit = (key & (1 << i));
        int index = current_bit - 0;
        // cout<<index<<endl;
        if(nodePtr->children[index] == nullptr){
            nodePtr->children[index] = new TrieNode;
        }
        nodePtr = nodePtr->children[index];
    }

    nodePtr->isEndOfWord = true;    
}

int max_xor(int a, TrieNode &root){
    TrieNode *nodePtr = &root;
    int res = 0;
    for(int i= 31; i>=0; i--){
        bool current_bit = (a &(1<<i));
        // cout<<current_bit<<' ';
        if(current_bit == true){
            if(nodePtr->children[0] != nullptr){    //current bit of result will be 1
                nodePtr = nodePtr->children[0];
                res=res|(1<<i);
            }
            else{                                  //current_bit in result will be 0
                nodePtr = nodePtr->children[1];
            }
        }
        else{
            if(nodePtr->children[1]!=nullptr){     //current bit of result will be 1
                nodePtr = nodePtr->children[1];
                res = res|(1<<i);
            }
            else{
                nodePtr = nodePtr->children[0];
            }
        }
    }
    return res;
}

int main(){
    int n ;
    cin>>n;
    vi A(n), B(n);
    for(int i = 0; i<n; i++){
        cin>>A[i];
    }
    for(int i = 0; i<n; i++){
        cin>>B[i];
    }

    TrieNode root;
    for(int i = 0; i<n; i++){
        insert(root, B[i]);
    }

    for(int i = 0; i<4; i++){
        cout<<max_xor(A[i], root)<<endl;
    }
}