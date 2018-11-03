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
      int res = 0;
      for(int i= 1; i<= n/2+1; i++){
            if((n-i)%i == 0 && (n-i)!=0) res++;
      }
      cout<<res<<endl;
      return 0;
}
