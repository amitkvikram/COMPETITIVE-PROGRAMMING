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
      i;
      parent = -1;
      sz = 1;
};

bool connected(int u, int v){
      return find(u) == find(v);
}

int find(auto &v, int u){
      while(u != v[u].parent){
            u = v[u].parent;
      }
      return u;
}

void union(auto &v, int u, int v){
      int x = find(u);
      int y = find(v);
      if(x == y) return;
      if(v[x].sz > v[y].sz){
            v[y].parent = x;
            v[x].sz += v[y].sz;
      }
      else(){
            v[x].parent = y;
            v[y].sz+=v[y].sz;
      }
}

int main(){
      int n;
      std::vector<graphNode> v(n);
      vi ind(n);
      rep(i, 0, n){
            cin>>v[i].i;
            v[i].i--;
            ind[v[i]] = i;
      }

      rep(i, 0, n){
            v[i].parent = i;
      }
      int a;

      rep(i, 0, n){
            rep(j, 0, n){
                  cin>>a;
                  if(a==1){
                        if(find(v[i].i != find(v[j].i){
                              union(v[i].i, v[j].i);
                        }
                  }
            }
      }

      std::vector<bool> vis(n, false);

      rep(i, 0, n){
            rep(j, 0, n){
                  if(vis[j] == false && connected(v[i].i, j)){
                        cout<<j++<<endl;
                        vis[j] = false;
                  }
            }
      }

}
