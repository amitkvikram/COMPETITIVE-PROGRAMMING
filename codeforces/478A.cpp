#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  int sum = 0, tmp;
  for(int i =0; i<5; i++){
    cin>>tmp;
    sum+=tmp;
  }
  if(sum%5 || sum == 0) cout<<"-1";
  else cout<<sum/5;
  return 0;
}
