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
      ll a, b;
      cin>>a>>b;
      while(a!=0 && b!=0){
            if(a>=2*b){
                  a = a-2*b;
                  continue;
            }
            if(b>2*a){
                  b = b-2*a;
                  continue;
            }
            else break;
      }

      cout<<
}
