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
      ll n, k;
      cin>>n>>k;
      vi c(n);
      rep(i,0, n){
            cin>>c[i];
      }

      sort(c.begin(), c.end());
      while(k){
            if(c[0]>=c[n-1]-1){
                  break;
            }
            else{
                  int diff = (c[n-1] - c[0])/2;
                  ll ind1 = upper_bound(c.begin(), c.end(), c[0]) - c.begin();
                  ind2 = lower_bound(c.begin(), c.end(), c[n-1]) - c.begin();
                  int tmp = ind1*c[0]+(n-ind2)*c[n-1];

            }
      }
      cout<<c[n-1]-c[0]<<endl;
}
