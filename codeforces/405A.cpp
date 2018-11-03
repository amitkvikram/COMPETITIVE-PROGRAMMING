#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  vi v(n);
  for(int i =0; i<n; i++){
    cin>>v[i];
  }

  sort(v.begin(), v.end());
  for(int i =0; i<n; i++){
    cout<<v[i]<<' ';
  }
  return 0;
}
