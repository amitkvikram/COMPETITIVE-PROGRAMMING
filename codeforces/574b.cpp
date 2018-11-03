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
public:
      list<int> adj;
      bool vis = false;
      int parent = -1;
}

int main(){
      int n, m;
      cin>>n>>m;

      vector<graphNode> v(n)

      int a, b;
      rep(i, 0, m){
            cin>>a>>b;
            v[a].adj.pb(b)
            v[b].adj.pb(a);
      }

      ll Max = 12020;
      rep(i, 0, n){
            vi cnt(n, 0);
            for(auto j: v[i].adj){
                  cnt[j] = 1;
            }
            for(auto j:v[i].adj){
                  for(auto k:v[j].adj){
                        if(cnt[k] == 1){
                              ll tmp = v[i].adj.size() + v[j].adj.size()+v[k].adj.size() - 6
                              if( <Max){
                                    Max = tmp;
                              }
                        }
                  }
            }
      }
      if(Max == 12020){
            cout<<"-1"<<endl;
      }
      else{
            cout<<Max<<endl;
      }
}
