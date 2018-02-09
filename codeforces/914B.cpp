#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
#define PB push_back

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  vi v(n);
  for(int  i= 0; i<n; i++) cin>>v[i];
  int count = 0;
  int max_num =0;
  for(int i =0; i<n; i++){
    if(v[i] >= max_num) max_num = v[i];
  }
  for(int i =0; i<n;i++){
    if(v[i]==max_num) count++;
  }
  if(count%2==0) cout<<"Agasa";
  else cout<<"Conan";
  return 0;
}
