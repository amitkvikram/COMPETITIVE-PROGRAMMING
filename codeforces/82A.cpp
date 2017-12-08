#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef std::vector<string> vi;

int main(int argc, char const *argv[]) {
  vi v = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
  ll n;
  cin>>n;
  ll a =0, b=5, i;
  for(i=5; b<n; i*=2){
    a=b;
    b+=(i*2);
  }

  // cout<<a<<' '<<b<<' ';

  ll t = a/5+1;

  t = (n-a-1)/t;
  // cout<<t;
  cout<<v[t];
  return 0;
}
