#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  int n, k;
  cin>>n>>k;
  vi v(n);
  for(int i =0; i<n; i++){
    cin>>v[i];
    v[i]= 5-v[i];
  }

  sort(v.begin(), v.end());
  int ind1 = v.end() - lower_bound(v.begin(), v.end(), k);
  cout<<ind1/3;
  return 0;
}
