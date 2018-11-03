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

void dfs(auto &v, auto &vis, auto &parent, auto &low, auto &disc, int i, int &time){
      low[i] = disc[i] = time++;
      vis[i] = true;
      for(auto &it:v[i]){
            if(vis[it] == false){
                  parent[it] = i;
                  dfs(v, vis, parent, low, disc, it, time);
                  if(low[it] > disc[i]) cout<<i<<"---"<<it<<endl;
                  low[i] = min(low[i],low[it]);
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
      std::vector<int> parent(n, -1);
      std::vector<int> low(n, 0);
      std::vector<int> disc(n, 0);

      rep(i, 0, n){
            if(vis[i] == false){
                  int time = 0;
                  dfs(v, vis, parent, low, disc, i, time);
            }
      }
}
