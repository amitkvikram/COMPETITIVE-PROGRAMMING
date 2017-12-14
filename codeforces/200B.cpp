#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  double tmp, sum =0;

  for(int i=0; i<n; i++){
    cin>>tmp;
    sum+=tmp;
  }

  cout<<std::fixed;
  cout<<setprecision(6);
  cout<<sum/(n);

  return 0;
}
