#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(int argc, char const *argv[]) {
  int n, tmp, sum =0, res = 0;
  cin>>n;
  while(n--){
    cin>>tmp;
    if(tmp == -1){
      if(sum>0) sum--;
      else res++;
    }
    else sum+=tmp;
  }
  cout<<res;
  return 0;
}
