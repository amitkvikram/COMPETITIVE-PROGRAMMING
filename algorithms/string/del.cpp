#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    vector<int> *adjList;
    node(vector<int> *v1 = new vector<int>()){
        cout << "Constructor: " << v1 << endl;
        adjList = v1;
    }
};

int main(){
    vector<node> v(4);
    cout << (*(v[0].adjList)).size() << endl;
    (*(v[0].adjList)).push_back(2);
    (*(v[0].adjList)).push_back(10);
    for (int i = 0; i < 4; i++){
        cout << (*(v[i].adjList)).size() << endl;
    }
}