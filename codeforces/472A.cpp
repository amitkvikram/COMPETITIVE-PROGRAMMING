#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef std::vector<int> vi;


int main() {
  int num;
  cin>>num;

  vi v(num+1, 0);
  int n = sqrt(num);
  for(int i =2; i<=n; i++){
    if(v[i]==0){
      for(int j=i*i; j<=num; j+=i ){
        v[j] = 1;
      }
    }
  }

  for(int i =4; i<num; i++){
    if(v[i]==1 && v[num-i]==1){
      cout<<i<<' '<<num-i;
      break;
    }
  }

  return 0;
}
