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

class Poll{
public:
      ll x;
      ll y;
};

class item{
public:
      Poll Pt;
      ll val;
};

class myCompare{
public:
      ll operator()(const item& p1, const item &p2){
            return p1.val>p2.val;
      }
};

bool isValid(auto &v, ll row, ll col, ll n, ll m){
      if((row>=0) && (row<n) && (col>=0) && (col<m)){
            if(v[row][col]!=-1) return true;
            else return false;
      }
      else return false;
}

void bfs(auto &v, auto &visited, ll n, ll m){
      priority_queue<item , vector<item>, myCompare> pq;
      rep(i, 0, n){
            rep(j,0, m){
                  if(v[i][j]>0){
                        pq.push({{i, j}, v[i][j]});
                  }
            }
      }

      while(!pq.empty()){
            Poll Pt = pq.top().Pt;
            ll val = pq.top().val;
            pq.pop();
            if(visited[Pt.x][Pt.y] == true) continue;
            visited[Pt.x][Pt.y] = true;
            rep(i, 0, 4){
                  ll x = Pt.x + rowNum[i];
                  ll y = Pt.y + colNum[i];
                  if(isValid(v, x, y, n, m) && visited[x][y] == false){
                        if(v[x][y]<v[Pt.x][Pt.y]-1){
                              v[x][y] = v[Pt.x][Pt.y]-1;
                              pq.push({{x, y}, v[x][y]});
                        }
                        else if(v[x][y] == 0 && v[Pt.x][Pt.y] == 1){
                              v[x][y] = -2;
                        }
                  }
            }
      }
}

int main() {
      ll t;
      cin>>t;
      while(t--){
            ll n, m;
            cin>>n>>m;
            vector<std::vector<ll>> v(n, std::vector<ll>(m));
            std::vector<std::vector<bool>> vis(n, std::vector<bool>(m, false));
            rep(i, 0, n){
                  rep(j, 0, m){
                        cin>>v[i][j];
                  }
            }
            bfs(v, vis, n, m);
            rep(i, 0, n){
                  rep(j, 0, m){
                        if(v[i][j] == -1){
                              cout<<'B';
                        }
                        else if(v[i][j] == 0){
                              cout<<'N';
                        }
                        else{
                              cout<<'Y';
                        }
                  }
                  cout<<endl;
            }
      }
      return 0;
}
