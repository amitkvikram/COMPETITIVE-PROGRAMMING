#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
#define PB push_back

class Graph{
    public:
        int n;
        int m;
        int res = 0;
}

class Vertex{
    public:
        bool visited = false;   //checks if vertex is visited or not
        int cat;                //stores if vertex contains a cat or not
        int parent = 0;         //stores parent of current vertex
        vector<int> adjList;    //stores adjacent vertex
        int max_cat             //stores max contiguous cats found till now
}

void dfs(Graph G, vector<Vertex> &node, int i, int max){
    node[i].visited = true;
    if(node[i].adjList.size()==1){
        if(max+node[i].cat<=G.m){
            G.res++;
            return;
        }
    }
    for(int j =0; i<node[j].adjList.size(); j++){
        int tmp = node[i].adjList[j];
        if(node[tmp].visited == false){
            node[tmp].parent = i;
            
        }
    }
}

int main(){
    Graph G;
    vector<Vertex> node;
    cin>>G.n>>G.m;
    for(int i = 0;i<G.n; i++){
        cin>>node.cat;
    }
    for(int i = 0; i<n-1; i++){
        int temp1, temp2;
        cin>>temp1>>temp2;
        node[temp1].adjList.PB(temp1);
        node[temp2].adjList.PB(temp2);
    }
    
    dfs(G, node, 0, node[0].cat);
    
}
