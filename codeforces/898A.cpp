#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;


int main(int argc, char const *argv[]) {
  ll n;
  cin>>n;
  int tmp1 = n/10, tmp2 = n%10;
  if(tmp2 == 0)  cout<<n;
  else{
    if(tmp2 <= 5){
      cout<<tmp1*10;
    }
    else cout<<(tmp1+1)*10;
  }
  return 0;
}
