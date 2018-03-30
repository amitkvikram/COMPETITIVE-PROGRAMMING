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

bool is_correct(ll n){
      vi cnt(10, 0);
      int num = 0;
      while(n){
            int t = n%10;
            cnt[t]++;
            num++;
      }

      if(num%2 == 0){
            num == 0;
            rep(i, 0, 10){
                  if(cnt[i]%2) num++;
            }
            if(num!=0) return false;
            else return true;
      }
      else return false;
}

int main(){
      vi v;
      for(i = 1; i<=200000; i++){
            if(is_correct(i)) v.pb(i);
      }

      int t;
      cin>>t;
      ll n;
      while(t--){
            cin>>n;
            int ind = lower_bound(v.begin(), v.end(), n) - v.begin();
            cout<<v[ind-1];
      }
}
