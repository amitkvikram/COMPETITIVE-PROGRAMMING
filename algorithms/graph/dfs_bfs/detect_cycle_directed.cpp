#include<bits/stdc++.h>
using namespace std;

class graphNode{
public:
      bool visited = false;
      int parent;
      bool previsit = false;
      bool postvisit = false;
      list<int> adjList;
};

bool dfs(std::vector<graphNode> v, int V, int s){
      v[s].previsit = true;
      v[s].visited = true;
      for(auto it = v[s].adjList.begin(); it!= v[s].adjList.end(); it++){
            if(v[*it].visited == false){
                  if(dfs(v, V, *it)) return true;
            }
            else if(v[*it].previsit == true && v[*it].postvisit == false){
                  return true;
            }
      }

      v[s].postvisit = true;
      return false;
}

bool detect_cycle(std::vector<graphNode> v, int V){
      for(int i = 0; i<V; i++){
            if(v[i].visited == false){
                  if(dfs(v, V, i, status)) return true;
            }
      }
      return false;
}

int main(){
      int V;
      cin>>V;

      std::vector<graphNode> v(V);
      int m, a, b; cin>>m;
      for(int i =0; i<m; i++){
            cin>>a>>b;
            v[a].adjList.push_back(b);
      }

      if(detect_cycle(v, V)) cout<<"Contains a Cycle\n";
      else cout<<"doesn't contain a cycle\n";
}
