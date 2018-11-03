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
      int parent = -1;
      bool visited = false;
      list<ll> adj;
};

int main(){
      ll n, m;
      cin>>n>>m;
      vi c(n);
      vector<vector<int>> color(100000);
      rep(i, 0, n){
            cin>>c[i];
            c[i]--;
            color[c[i]].pb(i);
      }

      vector<graphNode> v(n);
      ll a, b;
      rep(i, 0, m){
            cin>>a>>b;
            a--; b--;
            v[a].adj.pb(b);
            v[b].adj.pb(a);
      }

      ll Max = -1, res = 0;
      vi temp(100000, 0);
      rep(i, 0, 100000){
            ll tmp = 0;
            for(auto j:color[i]){
                 // cout<<j<<' ';
                  for(auto it:v[j].adj){
                        if(c[it]!=i && temp[c[it]]!=i){
                            tmp++;
                            temp[c[it]]=i;
                        }
                  }
            }
            if(tmp>Max && color[i].size()){
                  Max = tmp;
                  res = i;
            }
       }

   cout<<res+1<<endl;
}
