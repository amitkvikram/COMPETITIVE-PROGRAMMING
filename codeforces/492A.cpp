#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  int i=1;
  int sum = 1;
  while(sum<=n){
    i++;
    sum+=(i)*(i+1)/2;
  }

  cout<<i-1;
  return 0;
}
