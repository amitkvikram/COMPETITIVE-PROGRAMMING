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

ll rowNum[] = {-1, 0, 0, 1};
ll colNum[] = {0, -1, 1, 0};

int main(){
      ll n, k, a, b;
      cin>>n>>k>>a>>b;
      //cout<<n/k<<endl;
      if(k == 1 || k>n|| ((n/k)*k - (n/k))*a <= b){
            cout<<(n-1)*a;
            return 0;
      }
    ll x = n;
    ll cost = 0;
            while(x!=1){
                  if(x<k){
                           // cout<<"H"<<x<<endl;
                            cost+=(x-1)*a;
                            break;
                        }
                  if(((x/k)*k - (x/k))*a <= b){
                            cost+=(x-1)*a;
                            break;
                        }
                  if( ((x/k)*k - (x/k))*a > b){
                          cost+=(x-(x/k)*k)*a;
                          x = (x/k)*k;
                      }


                  if(x%k == 0){
                          cost+=b;
                            x/=k;
                  }
            }
          cout<<cost<<endl;


}
