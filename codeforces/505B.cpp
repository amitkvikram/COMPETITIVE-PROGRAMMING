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

int find(auto &v, int n, int m, int a, int c){
      while(v[c][a].ff != a){
            a = v[c][a].ff;
      }
      return a;
}

bool connected(auto &v, int n, int m, int a, int b, int c){
      return find(v, n, m, a, c) == find(v, n, m, b, c);
      int
}

void union1(auto &v, int n, int m, int a, int b, int c){
      int x = find(v, n, m, a, c);
      int y = find(v, n, m, b, c);
      if(x == y) return;
      if(v[c][x].ss < v[c][y].ss){
            v[c][x].ff = y;
      }
      else{
            v[c][y].ff = x;
      }
}

int main(){
      ll n, m;
      cin>>n>>m;
      int a, b, c;
      std::vector<std::vector<ii>> v(m, std::vector<int>(n));
      rep(i,0, m){
            rep(j, 0, n){
                  v[i][j].ff = j;
                  v[i][j].ss = 1;
            }
      }

      rep(i, 0, m){
            cin>>a>>b>>c;
            a--; b--; c--;
            union1(v, n, m, a, b, c);
      }

      int q;
      cin>>q;
      rep(i, 0, q){
            cin>>a>>b;
            a--; b--;
            int cnt = 0;
            rep(i, 0, m){
                  if(connected(v, n, m, a, b, m)) cnt++;
            }
            cout<<cnt<<endl;
      }
}
