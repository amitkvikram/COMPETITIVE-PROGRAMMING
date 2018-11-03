#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  ll n, m;
  cin>>n>>m;
  vi v(m);
  cin>>v[0];
  ll temp = v[0], dist= v[0]-1;
  for(int i =1; i<m; i++){
    cin>>v[i];
    if(v[i]>=temp) dist+=(v[i] - temp);
    else dist+=(n+v[i]-temp);
    temp = v[i];
  }

  cout<<dist;

  return 0;
}
