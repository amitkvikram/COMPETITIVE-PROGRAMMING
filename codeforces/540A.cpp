#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  int n;
  string num1, num2;
  int sum= 0;
  cin>>n>>num1>>num2;
  for(int i =0; i<n; i++){
    int tmp1 = num1[i] - '0'; int tmp2 = num2[i] - '0';
    sum+=min(abs(tmp1-tmp2), 10-max(tmp1, tmp2)+min(tmp1, tmp2)) ;
  }

  cout<<sum;
  return 0;
}
