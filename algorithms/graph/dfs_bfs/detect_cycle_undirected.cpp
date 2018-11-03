#include<bits/stdc++.h>
using namespace std;

class graphNode{
public:
      bool previsit = false;
      bool postvisit = false;
      list<int> adjList;
      bool visited = false;
};

bool dfs(std::vector<graphNode> &v, int V, int s, int parent){
      v[s].visited = true;
      for(auto it = v[s].adjList.begin(); it!=v[s].adjList.end(); it++){
            if(v[*it].visited == true){
                  if(*it!=parent) return true;
            }
            else{
                  if(dfs(v, V, *it, s)) return true;
            }
      }
      return false;
}

void print(std::vector<graphNode> &v, int V){
      for(int i =0; i<V; i++){
            cout<<i<<": ";
            for(auto it = v[i].adjList.begin(); it!=v[i].adjList.end(); it++){
                  cout<<*it<<' ';
            }
            cout<<endl;
      }
}

bool dfs_util(std::vector<graphNode> &v, int V){
      for(int i =0; i<V; i++){
            if(v[i].visited == false){
                  if(dfs(v, V, i, i)) return true;
            }
      }

      return false;
}

int main(){
      int V;
      cin>>V;
      std::vector<graphNode> v(V);
      int m, a, b;
      cin>>m;
      for(int i = 0; i<m; i++){
            cin>>a>>b;
            v[a].adjList.push_back(b);
            v[b].adjList.push_back(a);
      }
      print(v, V);
      bool cycle = dfs_util(v, V);
      cout<<cycle<<endl;
}
