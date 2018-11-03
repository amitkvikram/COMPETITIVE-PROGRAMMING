#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

class Square{
public:
  ll n;
  ll m;

  void numFlagstone(int a){
    if(n%a==0) n=n/a;
    else n=n/a+1;
    if(m%a==0) m= m/a;
    else m=m/a+1;

    cout<<n*m;
  }
};

int main(){
  Square square;
  cin>>square.n>>square.m;

  int a;
  cin>>a;

  square.numFlagstone(a);

  return 0;
}
