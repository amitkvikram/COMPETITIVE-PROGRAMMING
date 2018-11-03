#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<ll> vi;
vi cum_sum(2000001,0);

ll diamond_num(ll rm_n){
  ll sum_evn = 0, sum_odd = 0, tmp;
  while(rm_n){
    if((rm_n%10)%2) sum_odd+= (rm_n%10);
    else sum_evn+= (rm_n%10);
    rm_n=rm_n/10;
  }

  return abs(sum_odd - sum_evn);
}

int main() {

  for(int i =2; i<=2000000; i++){
      cum_sum[i]= cum_sum[i-1] + diamond_num(i);
  }

  vi cum_sum1(2000001,0);
  cum_sum1[2] = cum_sum[2];

  for(int i=3; i<=2000000; i++){
      cum_sum1[i] = cum_sum1[i-1] + cum_sum[i];
  }

  int t;
  cin>>t;
  ll sum = 0;

  while(t--){
    ll tot= 0;
    ll n, temp;
    cin>>n;

    tot = cum_sum1[2*n] - 2*cum_sum1[n];

    cout<<tot<<endl;
  }


  return 0;
}
