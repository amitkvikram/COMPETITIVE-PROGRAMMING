#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  int n,m, k;
  cin>>n>>m>>k;
  vi v(n);
  for(int i =0; i<n; i++){
    cin>>v[i];
  }
  sort(v.begin(), v.end());
  int cnt = 0;
  for(int i =0; i<n; i++){
      int ind = i+k-1;
      if(ind>=n) break;
      if(v[ind] - v[i] +1 <= m ){
        cnt++;
      }
  }
  cout<<cnt;
  return 0;
}
