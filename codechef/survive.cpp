#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
#define PB push_back
int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  while(t--){
    int n, k,s ;
    cin>>n>>k>>s;
    int i ;
    int choc = 0;
    for(i =1; i<=s; i++){
      if(i%7!=0) choc+=n;
      if(choc<k) break;
      else choc-=k;
    }

    if(i!=s+1) cout<<"-1"<<endl;
    else{
      if((k*s)%n==0) cout<<(k*s)/n;
      else cout<<(k*s)/n+1;
      cout<<endl;
    }
  }
  return 0;
}
