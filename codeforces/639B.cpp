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
      int n, d, h;
      cin>>n>>d>>h;
      if(d > n-1 ||  d<h || d>2*h ||(n>2 && h<2 && d==h)){
            cout<<"-1\n";
            return 0;
      }

      int prev = 0;
      rep(i, 1, h+1){
            cout<<prev+1<<' '<<i+1<<endl;
            prev = i;
      }

      if(d == h){
            rep(i, h+1, n){
                  cout<<"2 "<<i+1<<endl;
            }

            return 0;
      }

      prev = 0;
      rep(i, h+1, d+1){
            cout<<prev+1<<' '<<i+1<<endl;
          prev = i;
      }

      rep(i, d+1, n){
            cout<<"1 "<<i+1<<endl;
      }
}
