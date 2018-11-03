#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  int a, b;
  cin>>a>>b;
  if(b>a){
    int tmp =a;
    a = b;
    b = tmp;
  }

  cout<<b<<' '<<(a-b)/2;
  return 0;
}
