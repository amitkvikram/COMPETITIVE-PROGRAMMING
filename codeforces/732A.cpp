#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  int k, r;
  cin>>k>>r;
  int prc, i;
  for(i =1;i<=10*k; i++){
    prc = i*k;
    prc = prc%10;
    if(prc == r || prc == 0) break;
  }

  cout<<i;
  return 0;
}
