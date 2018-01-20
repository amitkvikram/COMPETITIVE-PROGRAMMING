#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef pair< string,vi> pr;

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  vi v(n);
  int cnt1 = 0, cnt2 = 0, cnt = 0;
  for(int i =0; i<n; i++){
    cin>>v[i];
    if(v[i]==2) cnt2++;
    else cnt1++;
  }

  if(cnt1>cnt2){
    cnt = cnt2+(cnt1-cnt2)/3;
  }

  else{
    cnt = cnt1;
  }

  cout<<cnt;

  return 0;
}
