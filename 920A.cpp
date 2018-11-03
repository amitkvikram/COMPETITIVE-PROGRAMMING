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

int main(){
      int t;
      cin>>t;
      while(t--){
            int n, k;
            cin>>n>>k;
            vi v(n+1, 0);
            int cnt = 0, a;
            rep(i, 0, k){
                  cin>>a;
                  v[a]=1;
                  cnt++;
            }
            int res = 0;
            while(cnt!=n){
                  vi tmp;
                  rep(i, 1, n+1){
                        if(v[i] == 1){
                              if(i-1>0){
                                    if(v[i-1] == 0){
                                          tmp.pb(i-1);
                                          cnt++;
                                    }
                              }
                              if(i+1<=n){
                                    if(v[i+1] == 0){
                                          tmp.pb(i+1);
                                          cnt++;
                                    }
                              }
                        }
                  }
                  for(auto i:tmp){
                        v[i] = 1;
                  }
                  res++;
            }
            cout<<res<<endl;
      }
}
