#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class TrieNode{
    public:
    TrieNode *children[26];
    bool isEndOfWord;
    int index;
    TrieNode(){
        for(int i = 0; i<26; i++){
            children[i] = nullptr;
        }
        isEndOfWord = false;
        index = -1;
    }
};

void insert(TrieNode &root, string &s, int index){
    TrieNode *rootPtr = &root;
    int n = s.size();

    for(int i = 0; i<n; i++){
        int index = s[i] - 'a';
        if(rootPtr->children[index] == nullptr){
            rootPtr->children[index] = new TrieNode;
        }

        rootPtr = rootPtr->children[index];
    }

    rootPtr->index = index;
}

void sort_print(const TrieNode *root, string s[]){
    for(int i = 0; i<26; i++){
        if(root->children[i] == nullptr) continue;
        if(root->children[i]->index != -1){
            cout<<s[root->children[i]->index]<<endl;
        } 
        sort_print(root->children[i], s);
    }
}

int main(){
    TrieNode root;
    int n;
    cin>>n;
    vi v(n);
    string s[n];
    for(int i = 0;i<n;i++){
        cin>>s[i];
    }
    for(int i = 0; i<n; i++){
        insert(root, s[i], i);
    }
    sort_print(&root, s);
}
