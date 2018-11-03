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
      int n;
      cin>>n;

      cout<<n+1<<endl;
      vi v(n+1);
      rep(i, 1, n+1){
            cout<<i<<' ';
      }
      cout<<n-1<<endl;
}
