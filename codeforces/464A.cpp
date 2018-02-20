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
      ll n;
      cin>>n;
      vi v(n, 0);
      int tmp;
      rep(i, 0, n){
            cin>>tmp;
            v[i] = tmp-1;
      }

      rep(i, 0, n){
            int a = i;
            int b= v[a];
            int c = v[b];
            if(v[c] == a){
                  cout<<"YES"<<endl;
                //cout<<i<<' '<<a<<' '<<b<<' '<<c<<' ';
                return 0;
            }
      }

      cout<<"NO"<<endl;
      return 0;

}
