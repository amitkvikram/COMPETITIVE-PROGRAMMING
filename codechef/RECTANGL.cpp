#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  while(t--){
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    if(a==b){
      if(c==d) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }
    else if(a==c){
      if(b==d) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }
    else if(a==d){
      if(b==c) std::cout << "YES" << '\n';
      else std::cout << "NO" << '\n';
    }
    else std::cout << "NO" << '\n';
  }

  return 0;
}
