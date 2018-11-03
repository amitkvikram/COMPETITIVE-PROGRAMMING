#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<ll> vi;
typedef vector<pair<ll, ll>> vpp;
#define PB push_back
ll L = 1e9 + 7;

ll pattern(string &str, ll n, ll i, vi &v, vpp &dp, ll *max){
//  cout<<i<<' '<<dp[i].first<<' '<<v[str[i]-'a']<<endl;
  if(i>n) return dp[n].first;
  vi count(26, 0);
  count[str[i-1]-'a']=1;
  for(ll j = 1; j<=i; j++){
    count[str[i-j]-'a']=1;
    ll flag = 0;
    for(ll i_t =0; i_t<26; i_t++){
      if(v[i_t] < j && count[i_t]==1){
        flag = 1;
        break;
      }
    }

    if(flag==1) break;
    if(j>*max) *max = j;
    if(dp[i].second>= dp[i-j].second+1) dp[i].second = dp[i-j].second+1;
    dp[i].first = (dp[i].first%L + dp[i-j].first%L)%L;
  }
  //cout<<i<<' '<<dp[i].first<<' '<<v[str[i]-'a']<<endl;
  ll tmp = pattern(str, n, i+1, v, dp, max);
  return tmp;
}

int main() {
  ll n;
  cin>>n;
  string str;
  cin>>str;
  vi v(26);
  for(ll i = 0; i<26; i++){
    cin>>v[i];
  }

  vpp dp(n+1, std::make_pair(0, INT_MAX));
  dp[0].first=1;
  dp[0].second=0;
  ll max = 0;
  ll res = pattern(str, n, 1, v, dp, &max);
  cout<<res<<endl<<max<<endl<<dp[n].second;
  return 0;
}
