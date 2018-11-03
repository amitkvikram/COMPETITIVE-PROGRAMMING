#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<ll> vi;

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  vi count(100001, 0);
  vi dp(100001, 0);
  ll tmp;
  for(int i =0; i<n; i ++){
    cin>>tmp;
    count[tmp]++;
  }

  dp[0] = 0;
  dp[1] = count[1];

  for(int i =2; i<100001; i++){
    dp[i] =  max(dp[i-1], dp[i-2]+i*count[i]);
  }

  cout<<dp[100000];
  return 0;
}
