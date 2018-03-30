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

int main(){
      int n;
      cin>>n;
      int a, b;
      std::vector<std::vector<int> v(n);
      rep(i, 1, n){
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
      }

      int level = 0;
      int cnt[2] = {0}, tmp, res = 0;
      queue<pari<int, int>> q;
      q.push(0);
      std::vector<bool> vis(n, false);
      vis[0] = true;
      while(!q.empty()){
            int t = q.front();
            q.pop();
            int i = t.ff;
            int l = t.ss;
            level = (1-l);
            for(auto it:v[i]){
                  if(vis[it] == false){
                        if(cnt[l]){
                              res+=cnt[l]-1;
                        }
                        q.push({it, level});
                  }
            }
      }
      cout<<res<<endl;
}
