#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<double> vi;

int main() {
  int n;
  double l;
  cin>>n>>l;
  vi v(n+1, 0);
  float err = 1e-9;
  for(int i =0; i<n; i++){
    cin>>v[i];
  }

  sort(v.begin(), v.end()-1);
  double max = v[0] - 0;
  for(int i = 0; i<n; i++){
    if(((v[i+1]-v[i])/2) - max >=err)  max = (v[i+1]-v[i])/2;
  }

  if((l - v[n-1]) - max >=err)  max = (l - v[n-1]);

  std::cout << std::fixed;
  std::cout << std::setprecision(10);
  cout<<max;
  return 0;
}
