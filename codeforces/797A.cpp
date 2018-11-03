//k-Factorization
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define rep(i,a,b) for(int i=a; i<b; i++)

int main(int argc, char const *argv[]) {

  int n,k, div=2, i=1;
  cin>>n>>k;
  vi v;

  while (n!=0) {
    if(n%div!=0) div++;
    else{
      n=n/div;
      i++;
      v.push_back(div);
    }
  }
    v.push_back(n);

  if (n<=1) {
    std::cout << "-1";
  }
  else{

    for(int j=0;j<k;j++){
      std::cout << v[j] << ' ';
    }
  }

  return 0;
}
