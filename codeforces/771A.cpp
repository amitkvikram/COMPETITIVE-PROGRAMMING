#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ff first
#define ss second
typedef pair< ll, ll > ii;
#define rep(i, a, b) for(ll i =a; i<b; i++)
#define pb push_back
typedef std::vector<ll> vi;
const ll mod = 1000000007;               //1e9+7

ll rowNum[] = {-1, 0, 0, 1};
ll colNum[] = {0, -1, 1, 0};

class graphNode{
      ll parent = -1;
      ll sz = 1;
};

void dfs(auto &v, auto &vis, auto &parent, ll n, ll &cnt, ll i){
      cnt++;
      vis[i] = true;
      for(auto &it:v[i]){
            if(vis[it] == false){
                  dfs(v, vis, parent, n, cnt, it);
            }
      }
}

ll num_edge(auto &v, ll n){
      ll num = 0;
      vi parent(n, -1);
      vector<bool> visited(n, false);
      rep(i, 0, n){
            ll cnt = 0;
            if(visited[i] == false){
                  dfs(v, visited, parent, n, cnt, i);
                  num+=(cnt)*(cnt-1)/2;
            }
      }
      return num;
}

int main(){
      ll n, m;
      cin>>n>>m;

      std::vector<vector<ll>> v(n, vector<ll>());
      ll a, b;
      rep(i, 0, m){
            cin>>a>>b;
            a--; b--;
            v[a].pb(b);
            v[b].pb(a);
      }
    //return 0;
      ll num = num_edge(v,n);
      if(num == m){
            cout<<"YES"<<endl;
      }
      else cout<<"NO\n";
}
