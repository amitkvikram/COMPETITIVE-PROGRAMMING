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
      int a, b;
      cin>>a>>b;
      int c = max(b,a);
      int d = c - min(b, a);
      int x = d/2, y = (d+1)/2;
      // cout<<d<<endl;
      // cout<<x<<' '<<y<<endl;
      int res = x*(x+1)/2;
      res+=(y*(y+1)/2);
      cout<<res<<endl;
}
