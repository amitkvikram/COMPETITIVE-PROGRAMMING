#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  int n, m, a, b;
  cin>>n>>m>>a>>b;

  int cnt = (n/m), tkt = cnt*m;
  if(cnt*b <= tkt*a){
    if((n-tkt)*a > b) cout<<(cnt+1)*b;
    else cout<<cnt*b + (n-tkt)*a;
  }
  else cout<<n*a;
  return 0;
}
