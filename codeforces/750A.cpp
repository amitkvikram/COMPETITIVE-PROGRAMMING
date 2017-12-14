#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  int n, k;
  cin>>n>>k;
  int min = 240-k;

  int i = 0, sum = 0;

  if(min<0){
    cout<<0;
    return 0;
  }

  while(sum <= min && i<=n){
    i++;
    sum=(i*(i+1)/2)*5;
  }

  cout<<i-1;
  return 0;
}
