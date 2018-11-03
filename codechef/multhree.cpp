#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
#define PB push_back

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  while(t--){
    ll k, d0, d1;
    cin>>k>>d0>>d1;
    if((((d0+d1)%10))%5!=0){
      //cout<<"Not divisible by 5"<<endl;
      ll sum2 = (d0+d1)%10, sum1 = sum2;
      ll n = k-3, r,ind=0;
      r = (sum2%10 + sum2%10)%10;

      //cout<<n<<' '<<ind<<' '<<r<<endl;

      ll tmp = n/4;
      ll res = (20*tmp);
      for(ll i =0; i<n%4; i++){
        res+=r;
        r = (r*2)%10;
      }
      //cout<<res<<endl;
      res+=(d0+d1);
      res+=(d0+d1)%10;
      //cout<<res<<endl;
      if(res%3==0) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }

    else{
      cout<<"NO"<<endl;
    }

  }
  return 0;
}
