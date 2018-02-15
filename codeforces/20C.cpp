#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<ll> vi;
typedef std::vector<std::vector<ll>> vvi;
#define INF 1e18

class edge{
public:
      ll wt;
      ll dest;
};

class item{
    public:
      ll dist;
      ll ind;
};

typedef std::vector< list<edge> > vl;

class myCompare
{
public:
    int operator() (const item& p1, const item& p2)
    {
        return p1.dist>p2.dist;
    }
};
void print_path(vi &parent, int ind){
      if(ind == 0){
            cout<<"1 ";
            return;
      }
      print_path(parent, parent[ind]);
      cout<<ind+1<<' ';
}

void dijkstra(vl &v, int n){
      priority_queue<item, vector<item>, myCompare > pq;
      vi dist(n, INF);
      vector<bool> visited(n, false);
      vi parent(n, 0);
      dist[0] = 0;
      pq.push({0, 0});

      while(!(pq.empty())){
                  int u = pq.top().ind;
                  pq.pop();
                  visited[u] = true;
                  //cout<<u<<' '<<dist[u]<<endl;
                  for(auto it = v[u].begin(); it!= v[u].end(); it++){
                        //cout<<(*it).dest<<" "<<(*it).wt<<' '<<dist[u]<<' '<<dist[(*it).dest]<<endl;
                        if(visited[(*it).dest] == false && dist[(*it).dest] > dist[u] + (*it).wt){
                              //cout<<(*it).dest<<" "<<(*it).wt<<' '<<dist[u]<<' '<<dist[(*it).dest]<<endl;
                              dist[(*it).dest] = dist[u] + (*it).wt;
                              pq.push({dist[(*it).dest], (*it).dest});
                              parent[(*it).dest] = u;
                        }
                  }
      }

      if(dist[n-1] == INF){
            cout<<"-1"<<endl;
            return;
      }
      int ind = n-1;
      print_path(parent, n-1);
      cout<<endl;
}

int main(){
      int n, m;
      cin>>n>>m;
      vl v(n);
      int a, b, wt;
      for(int i = 0; i<m; i++){
            cin>>a>>b>>wt;
            a--; b--;
            v[a].push_back({wt, b});
            v[b].push_back({wt, a});
      }

      dijkstra(v, n);
}
