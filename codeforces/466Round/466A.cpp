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
      int n, d;
      cin>>n>>d;

      vi v(n);
      rep(i, 0, n){
            cin>>v[i];
      }

      sort(v.begin(), v.end());

      int i2 = n-1, i1 = 0;
      while(i2!=i1){
            if(v[i2] - v[i1] <= d ) break;
            if(v[i2 - 1] - v[i1] < v[i2] - v[i1+1] ){
                  i2--;
            }
            else{
                  i1++;
            }
      }

      cout<<n-(i2+1- i1)<<endl;
}
