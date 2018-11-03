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
            int n;
            cin>>n;
            int l, r;
            int t = 0;
            cin>>l>>r;
            t = l+1;
            cout<<l<<' ';
            rep(i, 1, n){
                  cin>>l>>r;
                  if(t>r){
                        cout<<0<<' ';
                        continue;
                  }
                  else{
                        cout<<t<<' ';
                        t++;
                  }
            }
            cout<<endl;
      }
}
