#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class graphNode{
public:
      bool visited = false;
      list< pair<int, int> > adjList;           //destination vertex index no. and weight of Edge
      int dist = -1000;
};

void dfs(std::vector<graphNode> &v, int V, stack<int> &Topological, int s){
      v[s].visited = true;
      for(auto it = v[s].adjList.begin(); it!= v[s].adjList.end(); it++){
            if(v[(*it).first].visited == false){
                  dfs(v, V, Topological, (*it).first);
            }
      }

      Topological.push(s);
}

void topologicalSort(std::vector<graphNode> &v, int V, stack<int> &Topological){
      for(int i =0; i<V; i++){
            if(v[i].visited == false){
                  dfs(v, V, Topological, i);
            }
      }
}

void longest_path(std::vector<graphNode> &v, int V, stack<int> &Topological, int s){
      v[s].dist = 0;
      while(!Topological.empty()){
            int tmp = Topological.top();
            Topological.pop();
            if(v[tmp].dist!=-1000){
                  for(auto it = v[tmp].adjList.begin(); it!= v[tmp].adjList.end(); it++){
                        if(v[(*it).first].dist< v[tmp].dist + (*it).second){
                              v[(*it).first].dist = v[tmp].dist + (*it).second;
                        }
                  }
            }
      }

      cout<<"Longest Path from "<<s<<endl;
      for(int i =0; i<V; i++){
            (v[i].dist==-1000)?cout<<"INF ":cout<<v[i].dist<<' ';
      }
      cout<<endl;
}

int main(){
      int V;
      cin>>V;
      std::vector<graphNode> v(V);
      int m, a, b, c;
      cin>>m;
      for(int i =0; i<m; i++){
            cin>>a>>b>>c;
            v[a].adjList.push_back({b, c});
      }

      //Assuming graph is a dag
      stack<int> Topological;
      topologicalSort(v, V, Topological);
      // while(!Topological.empty()){
      //       cout<<Topological.top()<<' ';
      //       Topological.pop();
      // }

      int source;
      cin>>source;
      longest_path(v, V, Topological, source);
}
