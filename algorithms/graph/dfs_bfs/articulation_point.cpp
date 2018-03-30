#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ff first
#define ss second
typedef pair< ll, ll > ii;
#define rep(i, a, b) for(ll i =a; i<b; i++)
#define pb push_back
typedef std::vector<ll> vi;
const int mod = 1000000007;               //1e9+7

void dfs(auto &v, auto &vis, auto &low, auto &disc, auto &ap, auto &parent, int i, int &time){
      vis[i] = true;
      disc[i] = time++;
      low[i] = disc[i];
      int child = 0;
      for(auto &it:v[i]){
            if(vis[it] == false){
                  child++;
                  parent[it]=i;
                  dfs(v, vis, low, disc, ap,parent, it, time);
                  low[i] = min(low[it], low[i]);
                  if(parent[i] == -1 && child>1){ap[i] = true;}
                  else if(parent[i]!=-1 && low[it] >= disc[i] ){ap[i] = true;}
            }
            else if(parent[i]!=it){
                  low[i] = min(low[i], disc[it]);
            }
      }
}

int main(){
      int n, m;
      cin>>n>>m;
      std::vector<std::vector<int>> v(n);
      int a, b;
      rep(i, 0, m){
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
      }

      std::vector<bool> vis(n, false);
      std::vector<ll> low(n, 0);
      vi disc(n, 0);
      vi parent(n, -1);
      std::vector<bool> ap(n, false);

      rep(i, 0, n){
            if(vis[i] == false){
                  int time = 0;
                  dfs(v, vis, low, disc,ap, parent, i, time);
            }
      }

      rep(i, 0, n){
            if(ap[i] == true){
                  cout<<i<<' ';
            }
      }
}
