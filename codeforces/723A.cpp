#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  int x1, x2, x3;
  cin>>x1>>x2>>x3;
  int max = 500, tmp;
  for(int i =1; i<200; i++){
   tmp = abs(x1-i) + abs(x2 - i) +  abs(x3-i);
   if(tmp<=max) max = tmp;
  }

  cout<<max;
  return 0;
}
