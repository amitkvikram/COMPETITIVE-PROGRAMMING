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
      ll n, q;
      cin>>n>>q;
      ll f_1, f_2;
      cin>>f_1>>f_2;
      ll a, b;
      cin>>a>>b;
      vi v(n+1), f(n+1, 0);
      f[1] = f_1; f[2] = f_2;
      rep(i, 3, n+1){
            f[i] = (a*f[i-2]%mod + b*f[i-1]%mod)%mod;
      }
      rep(i, 1, n+1){
            cin>>v[i];
      }
      int l, r;
      vi p(n+1, 0);
       //q = 2;
      while(q--){
                  cin>>l>>r;
                  //cout<<l<<' '<<r<<endl;
                  if(l==r){
                      p[l] = (p[l]%mod + f[1]%mod)%mod;
                      if(r+1<=n) p[r+1] = (((p[r+1]%mod - (b*f[1])%mod)%mod)+mod)%mod;
                      if(r+2<=n) p[r+2] = (((p[r+2]%mod - (a*f[1])%mod)%mod)+mod)%mod;
                      continue;
                  }
                  p[l] = (p[l]%mod + f[1]%mod)%mod;
                  p[l+1] = (p[l+1]%mod + f[2]%mod)%mod;
                  p[l+1] =  ((p[l+1]%mod - (b*f[1])%mod)+mod)%mod;
                  if(r+1 <= n) p[r + 1] = (((p[r+1]%mod - ((a*f[r-l])%mod + (b*f[r-l+1])%mod)%mod)%mod)+mod)%mod;
                  if(r+2<=n) p[r+2] = (((p[r+2]%mod - (a*f[r-l+1])%mod)%mod)+mod)%mod;
      }
      rep(i, 2, n+1){
          p[i] = ((p[i]%mod + ((a* p[i-2])%mod + b*p[i-1]%mod))%mod)%mod;
      }

      rep(i, 1, n+1){
            v[i] = (v[i]%mod + p[i]%mod)%mod;
            cout<<v[i]<<' ';
      }

}
