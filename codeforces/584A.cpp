#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  int n, t;
  cin>>n>>t;
  if(t==10 && n==1) cout<<"-1";
  else{
    if(n==1) cout<<t;
    else{
      cout<<t;
      if(t==10) n-=1;
      while(--n){
        cout<<"0";
      }
    }
  }
  return 0;
}
