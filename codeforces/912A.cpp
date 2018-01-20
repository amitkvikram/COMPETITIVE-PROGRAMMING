#include <bits/stdc++.h>
using namespace std;
typedef std::vector<long long> vi;


int main(int argc, char const *argv[]) {
  long long a, b;
  cin>>a>>b;
  long long x, y, z;
  cin>>x>>y>>z;
  long long blue = 0, yellow = 0;
  blue = y+3*z;
  yellow = 2*x+y;
  //cout<<blue<<endl<<yellow<<endl;
  if(blue>b) blue-=b;
  else blue = 0;
  if(yellow>a) yellow-=a;
  else yellow = 0;
  cout<<(blue+yellow);
  return 0;
}
