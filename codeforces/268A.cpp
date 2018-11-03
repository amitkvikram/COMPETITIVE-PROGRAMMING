#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector< pair <int,int> > vi;    //home uniform , guest uniform

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  int a, b, gm = 0;
  vi v;
  for(int i =0; i<n; i++){
    cin>>a>>b;
    v.push_back(make_pair(a, b));
  }

  for(int i=0; i<n; i++){
    for(int j = i+1; j<n; j++){
      if(v[i].first == v[j].second) gm++;
      if(v[i].second == v[j].first) gm++;
    }
  }

  cout<<gm;

  return 0;
}
