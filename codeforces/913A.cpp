#include <bits/stdc++.h>
using namespace std;

typedef std::vector<int> vi;
typedef long long ll;

int main(int argc, char const *argv[]) {
  ll m, n;
  cin>>n>>m;
  int i = 0;
  for(i =0; i<40; i++){
    if(pow(2,i)>m) break;
  }
  if(n>=i) cout<<m<<endl;
  else{
    cout<<m%(int)pow(2,n)<<endl;
  }

  return 0;
}
