#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ff first
#define ss second
typedef pair< ll, ll > ii;
#define rep(i, a, b) for(ll i =a; i<b; i++)
#define pb push_back
typedef std::vector<ll> vi;
const int mod = 1000000007;

int main(){
      ll n, k;
      cin>>n>>k;
      vi v(k);
      rep(i, 0, k){
            cin>>v[i];
      }

      ll min = 1e18, ind;
      rep(i, 0, k){
            if(n%v[i]<min){
                  min = n%v[i];
                  ind = i+1;
            }
      }

      cout<<ind<<' '<<n/v[ind-1]<<endl;
}
