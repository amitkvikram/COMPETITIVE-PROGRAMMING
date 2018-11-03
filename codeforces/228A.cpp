#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  vi v(4);
  int cnt = 0, flag = 1;
  for(int i =0; i<4; i++){
    cin>>v[i];
    flag = 1;
    for(int j =0; j<i; j++){
      if(v[j] == v[i]) flag = 0;
    }
    if(flag) cnt++;
  }

  cout<<4-cnt;
  return 0;
}
