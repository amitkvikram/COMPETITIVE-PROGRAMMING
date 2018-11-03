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

int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};
vector<std::vector<int>> v(1000, std::vector<int> (1000, 0));
vector<std::vector<bool>> vis(1000, std::vector<bool> (1000, false));

void dfs(int i, int j){
      vis[i][j] = true;
      rep(it, 0, 1000){
            if(vis[i][it] == false && v[i][it] == 1){
                  dfs(i, it);
            }
            if(vis[it][j] == false && v[it][j] == 1){
                  dfs(it, j);
            }
      }
}

int main(){
      int n;
      cin>>n;

      int a, b;
      rep(i, 0, n){
            cin>>a>>b;
            a--; b--;
            v[a][b] = 1;
      }

      int cnt = 0;
      rep(i, 0, 1000){
            rep(j, 0, 1000){
                  if(v[i][j]==1 && vis[i][j] == false){
                        cnt++;
                        dfs(i, j);
                  }
            }
      }
      cout<<cnt-1<<endl;
}
