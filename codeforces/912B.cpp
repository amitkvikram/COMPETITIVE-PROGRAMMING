#include <bits/stdc++.h>
using namespace std;
typedef std::vector<long long> vi;
typedef long long ll;

int main(int argc, char const *argv[]) {
  ll n, k;
  cin>>n>>k;
  vi v;
  ll n1 = n;
  while(n>0){
    v.push_back(n%2);
    n/=2;
  }

  ll res;
  if(k>1){
    res = pow(2, v.size())-1;
  }
  else res = n1;
  cout<<res;
  return 0;
}
