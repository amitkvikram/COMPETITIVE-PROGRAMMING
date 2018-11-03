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
      ll s, k;
      cin>>s>>k;

      vi v;
      ll cnt = 1, sum = 1, prev = -1;
      v.pb(1);
      if(s==1){
          cout<<1<<endl<<1<<endl;
          return 0;
      }
      for(int i =0; i<50; i++){
            v.pb(sum);
            sum+=v.back();
            if(cnt>=k){
                  prev++;
            }
            else cnt++;
            if(prev!=-1){
                  sum-=v[prev];
            }
      }
       cnt = 0;
    vi tmp;
    int ind = lower_bound(v.begin(), v.end(), s) - v.begin();
    if(s!=v[ind]){
        s-=v[ind];
        tmp.pb(v[ind]);
    }
    else{
        s-=v[ind-1];
        tmp.pb(v[ind-1]);
    }
      while(s){
          ind = lower_bound(v.begin(), v.end(), s) - v.begin();
          s-=v[ind-1];
          tmp.pb(v[ind-1]);
          cnt++;
      }

    cout<<cnt<<endl;
    for(auto i:tmp){
        cout<<i<<' ';
    }
    cout<<endl;
}
