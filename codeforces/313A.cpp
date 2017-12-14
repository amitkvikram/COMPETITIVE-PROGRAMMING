#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  vi v;
  if(n>=0) cout<<n;
  else{
    n=-n;
    int i = 2;
    while(i--){
      v.push_back(n%10);
      n = n/10;
    }
    n*=10;
    n+=min(v[0], v[1]);
    cout<<-n;
  }
  return 0;
}
