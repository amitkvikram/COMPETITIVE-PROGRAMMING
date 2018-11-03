#include<bits/stdc++.h>
using namespace std;

class graphNode{
public:
      int visited = false;
      int dist = 0;
      list<int> adjList;
};

void dfs(std::vector<graphNode> &v, int s){     //s stands for source
      v[s].visited = true;
      for(auto it = v[s].adjList.begin(); it!=v[s].adjList.end(); it++){
            if(v[*it].visited == false){
                  dfs(v, *it);
            }
      }
}

void dfs_util(std::vector<graphNode> v, int V){
      for(int i =0; i<V; i++){
            if(v[i].visited == false){
                  dfs(v, i);
            }
      }
}

int main() {
      int V;
      cin>>V;
      std::vector<graphNode> v(V);
      int m;
      cin>>m;
      int a, b, c;                  //delete c while implementing
      for(int i =0; i<m; i++){
            cin>>a>>b>>c;
            v[a].adjList.push_back(b);
      }

      dfs_util(v, V);

      return 0;
}
