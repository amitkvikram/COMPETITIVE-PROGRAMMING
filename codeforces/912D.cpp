#include <bits/stdc++.h>
using namespace std;
typedef std::vector<long long> vi;
typedef long long ll;

int main(int argc, char const *argv[]) {
  ll n, m, r, k;
  cin>>n>>m>>r>>k;

  std::vector< std::vector<int> > v(n, std::vector<int> (m, 0));

  for(int i =0; i<n; i++){
    for(int j =0; j<m; j++){
      if(i<r && j<r) v[i][j]= (i+1)+j+1;
      else if(i>=r && j<r) v[i][j]=r*(j+1);
      else if((i<r && j>=r)) v[i][j] = r*(i+1);
      else v[i][j]= r*r;
    }
  }

  for(int i =0; i<n; i++){
    for(int j =0; j<m; j++){
      cout<<v[i][j]<<' ';
    }
    cout<<endl;
  }
  return 0;
}
