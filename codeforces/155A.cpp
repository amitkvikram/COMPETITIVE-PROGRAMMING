#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  vi v(n);
  cin>>v[0];
  int min = v[0], max = v[0];
  int cnt = 0;
  for(int i = 1; i<n ;i ++){
    cin>>v[i];
    if(v[i]>max || v[i]<min){
       cnt++;
       if(v[i]>max) max = v[i];
       else if(v[i]<min) min = v[i];
    }
  }
      cout<<cnt;
  return 0;
}
