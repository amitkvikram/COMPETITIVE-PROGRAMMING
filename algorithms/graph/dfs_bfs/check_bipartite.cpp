#include<bits/stdc++.h>
using namespace std;

class graphNode{
public:
      bool visited = false;
      list<int> adjList;
      int color;
};

bool dfs(std::vector<graphNode> &v, int V, int s){
      v[s].visited = true;
      cout<<s<<' ';
      for(auto it = v[s].adjList.begin(); it!= v[s].adjList.end(); it++){
            if((v[*it].visited && (v[*it].color == v[s].color)) || *it == s) return false;
            if(v[*it].visited == false){
                  v[*it].color = 1-(v[s].color/1);
                  if(!dfs(v, V, *it)) return false;
            }
      }

      return true;
}

bool bipartite(std::vector<graphNode> &v, int V){
      for(int i =0; i<V; i++){
            if(!v[i].visited){
                  v[i].color = 0;
                  if(!dfs(v, V, i)) return false;
            }
      }

      return true;
}

int main(){
      int V;
      cin>>V;
      std::vector<graphNode> v(V);
      int m, a, b;
      cin>>m;
      for(int i =0; i<m; i++){
            cin>>a>>b;
            v[a].adjList.push_back(b);
      }

      if(bipartite(v, V)){
            cout<<"graph is bipartite"<<endl;
      }
      else{
            cout<<"graph is not bipartite\n";
      }
}
