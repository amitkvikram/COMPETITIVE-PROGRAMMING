#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<ll> vi;
#define PB push_back

int Square(ll n){
  for(int i =0; i<=1000; i++){
    if(n == i*i){
     return 0;
    }
  }
  return 1;
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  vi v(n);
  int max = -1e6;
  for(int i =0; i<n; i++) cin>>v[i];
  for(int i =0; i<n; i++){
    if(Square(v[i]) || v[i]<0){
      if(v[i]>=max) max = v[i];
    }
  }

  cout<<max<<endl;
  return 0;
}
