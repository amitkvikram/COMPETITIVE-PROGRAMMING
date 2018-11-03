#include<bits/stdc++.h>
using namespace std;

class graphNode{
public:
      list<int> adjList;
      int dist = 1000;
      int parent;
      bool visited = false;
};

class graph{
public:
      int V;            //no of vertices
      // std::vector<graphNode> v(26);
      std::vector<graphNode> v;
      graph(int n): V{n} , v(n){}
      void read();
      void print();
      void bfs(int source);
      void shortest_path();
};

void graph::read(){
      int m, a, b, c;
      cin>>m;

      for(int i =0; i<m; i++){
            cin>>a>>b>>c;
            v[a].adjList.push_back(b);
            v[b].adjList.push_back(a);
      }
}

void graph::print(){
      cout<<"------\n";
      cout<<V<<endl;
      for(int i =0; i<V; i++){
            cout<<i<<": ";
            for(auto it = v[i].adjList.begin(); it!=v[i].adjList.end(); it++){
                  cout<<*it<<' ';
            }
            cout<<endl;
      }
      cout<<"-------\n";
}

void graph::bfs(int source){
      v[source].dist = 0;
      queue<int> q;
      q.push(source);
      while(!q.empty()){
            int temp = q.front();
            cout<<temp<<": ";
            q.pop();
            v[temp].visited = true;
            for(auto it = v[temp].adjList.begin(); it!=v[temp].adjList.end(); it++){
                  if(v[*it].visited == false){
                        q.push(*it);
                        cout<<*it<<' ';
                        v[*it].dist = v[temp].dist+1;
                        v[*it].visited = true;
                  }
            }
            cout<<endl;
      }
}

void graph::shortest_path(){
      for(int i =0; i<V; i++){
            cout<<v[i].dist<<' ';
      }
      cout<<endl;
}

int main() {
      int n;
      cin>>n;
      graph G(n);
      G.read();
      G.print();
      int source;
      cin>>source;
      cout<<"Source: "<<source<<endl;
      G.bfs(source);
      G.shortest_path();
      return 0;
}
