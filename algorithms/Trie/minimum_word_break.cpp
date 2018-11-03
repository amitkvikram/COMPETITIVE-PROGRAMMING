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

    ~TrieNode(){

    }
};

class vertex{
    public:
    vector<int> adj;
    bool visited = false;
    bool string_exist = false;
};

void insert(TrieNode &root, string &s){
    TrieNode *nodePtr = &root;
    for(int i = 0; i<s.size(); i++){
        int index = s[i] - 'a';
        if(nodePtr->children[index] == nullptr){
            nodePtr->children[index] = new TrieNode;
        }

        nodePtr = nodePtr->children[index];
    }

    nodePtr->isEndOfWord = true;
}

bool word_break(TrieNode *rootPtr, string &s, int ind, vector<vertex> &v){
    if(ind >= s.size()){
        return true;
    }
    if(v[ind].visited == true){
        // cout<<"returning "<<ind<<endl;
        return v[ind].string_exist;
    }

    v[ind].visited = true;
    TrieNode *nodePtr = rootPtr;
    bool res = false;
    for(int i = ind; i < s.size(); i++){
        int index = s[i] - 'a';
        if(nodePtr->children[index] == nullptr){
            // cout<<"Breaking "<<ind<<s[i]<<i<<endl;
            break;
        } 
        
        if(nodePtr->children[index]->isEndOfWord == true){
            // cout<<"found\n";
            if(word_break(rootPtr, s, i+1, v)){
                res = true;
                v[ind].adj.push_back(i+1);
            } 
        }

        nodePtr = nodePtr->children[index];
    }

    v[ind].string_exist = res;
    return res;
}

void dfs(vector<vertex> &v, int ind, string s, int n, string &orig){
    // cout<<ind<<' '<<v[ind].adj.size()<<endl;
    if(ind == n){
        cout<<s<<endl;
        return;
    }
    for(auto elem:v[ind].adj){
        dfs(v, elem, s +orig.substr(ind, elem - ind) + " ", n, orig);
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

    cin>>s;
    vector<vertex> v(s.size());
    word_break(&root, s, 0, v);
    dfs(v, 0, "", s.size(), s);
    return 0;
}