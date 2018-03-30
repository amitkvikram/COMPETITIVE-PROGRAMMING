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

int main(){
      int n;
      cin>>n;
      vi v1, v2;
      ll a;
      rep(i, 0, n){
            cin>>a;
            if(a<=0) v2.pb(a);
            else v1.pb(a);
      }
      ll sum1 = 0, sum2  = 0;
      rep(i, 0, v1.size()){
            sum1+=v1[i];
      }
      rep(i, 0, v2.size()){
            sum2+=v2[i];
      }
      cout<<sum1-(sum2)<<endl;
}
