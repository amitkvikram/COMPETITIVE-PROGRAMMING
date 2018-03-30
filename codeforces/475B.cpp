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

bool check_ind(ll n, ll m, ll i, ll j){
      return (i<n && j<m);
}

void dfs1(auto &H, auto &V, auto &vis, ll n, ll m, ii ind, auto &st){
      ll i = ind.ff;
      ll j = ind.ss;
      vis[i][j] = true;
      if(H[i] == '<'){
            if(check_ind(n, m, i-1, j) && vis[i-1][j] == false){
                  dfs1(H, V, vis, n, m, {i-1, j}, st);
            }
      }
      else{
            if(check_ind(n, m, i+1, j)  && vis[i+1][j] == false){
                  dfs1(H, V, vis, n, m, {i+1, j}, st);
            }
      }
      if(V[i] == '^'){
            if(check_ind(n, m, i, j-1) && vis[i][j-1] == false){
                  dfs1(H, V, vis, n, m, {i, j-1}, st);
            }
      }
      else{
            if(check_ind(n, m, i, j+1) && vis[i][j+1] == false){
                  dfs1(H, V, vis, n, m, {i, j+1}, st);
            }
      }
      st.push({i, j});
}

void dfs(auto &H, auto &V, auto &vis, ll n, ll m, ii ind){
      ll i = ind.ff;
      ll j = ind.ss;
      vis[i][j] = true;
      if(H[i] == '>'){
            if(check_ind(n, m, i-1, j) && vis[i-1][j] == false){
                  dfs(H, V, vis, n, m, {i-1, j});
            }
      }
      else{
            if(check_ind(n, m, i+1, j)  && vis[i+1][j] == false){
                  dfs(H, V, vis, n, m, {i+1, j});
            }
      }
      if(V[i] == 'v'){
            if(check_ind(n, m, i, j-1) && vis[i][j-1] == false){
                  dfs(H, V, vis, n, m, {i, j-1});
            }
      }
      else{
            if(check_ind(n, m, i, j+1) && vis[i][j+1] == false){
                  dfs(H, V, vis, n, m, {i, j+1});
            }
      }
}

bool check(ll n, ll m, auto &H, auto &V){
      stack<ii> st;
      vector<std::vector<bool>> vis(n, std::vector<bool> (m, false));
      dfs1(H, V, vis, n, m, {0, 0}, st);
      rep(i, 0, n){
            rep(j, 0,m){
                  if(vis[i][j]== false) return false;
            }
      }

      ii tmp = st.top();
      st.pop();
      rep(i, 0, n){
            rep(j, 0, m){
                  vis[i][j] = false;
            }
      }

      dfs(H, V, vis, n, m, tmp);
      while(!st.empty()){
            tmp = st.top();
            st.pop();
            if(vis[tmp.ff][tmp.ss] == false) return false;
      }

      return true;
}

int main(){
      ll n, m;
      cin>>n>>m;

      vector<char> H(n);
      vector<char> V(m);
      char ch;
      rep(i, 0, n){
            scanf("%c",&H[i]);
      }
      rep(i, 0, m){
            scanf("%c",&V[i]);
      }

      if(check(n,m, H, V)) cout<<"YES\n";
      else cout<<"NO\n";
}
