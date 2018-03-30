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
      list<int> adj;
};

int dfs(auto &v, int i){
      //cout<<i<<' ';
      v[i].visited = true;
      int num = 0;
      for(auto it:v[i].adj){
            if(v[it].visited == false){
                  num+=dfs(v, it);
            }
      }
      //cout<<num<<endl;
      return num+1;
}

int main(){
      int n, m, k;
      cin>>n>>m>>k;

      vector<ii> c(k);
      rep(i, 0, k){
            cin>>c[i].ff;
            c[i].ff--;
      }

      std::vector<graphNode> v(n);
      int a, b;
      rep(i, 0,m){
            cin>>a>>b;
            a--; b--;
            //cout<<a<<' '<<b<<endl;
            v[a].adj.pb(b);
            v[b].adj.pb(a);
      }


      int res = 0, Max = 0, ind = 0;
      rep(i, 0, k){
            c[i].ss = dfs(v, c[i].ff);
            //cout<<c[i].ss<<' ';
            if(c[i].ss>Max){
                  Max = c[i].ss;
                  ind = i;
            }
      }
     //return 0;
      int num = 0;
      rep(i, 0, n){
            if(v[i].visited == false){
                  num++;
            }
      }
      c[ind].ss+=num;

      rep(i, 0, k){
            res+=(c[i].ss*(c[i].ss-1))/2;
      }

      cout<<res-m<<endl;
}
