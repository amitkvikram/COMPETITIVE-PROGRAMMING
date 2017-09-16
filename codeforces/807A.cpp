//IS IT RATED?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define REP(i,a,b) for(int i=a; i<b; i++)

int main(int argc, char const *argv[]) {
  int n, flag=0;
  std::cin >> n;
  vi v1,v2;

  int a,b;

  REP(i, 0, n){
    std::cin >> a >>b;
    v1.push_back(a);
    v2.push_back(b);
    if (a!=b) {
        flag=1;
    }
  }

  if (flag==1) {
    std::cout << "rated" << '\n';
  }

  else{
    flag =0;
    vi v3(v1);
    sort(v3.begin(), v3.end(),std::greater<int>());
    REP(i, 0, n){
      if (v3[i]!=v1[i]) {
        flag=1;
      }
    }

    if (flag==0) {
      std::cout << "maybe" << '\n';
    }

    else{
      std::cout << "unrated" << '\n';
    }

  }

  return 0;
}
