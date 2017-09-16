#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define REP(i,a,b) for(int i=a; i<b; i++)

int main(int argc, char const *argv[]) {
  ll n;
  std::cin >> n;

  ll temp=n, count=1, num;

  while (temp){
    num= temp%10;
    temp=temp/10;
    count*=10;
  }
  num+=1;
  std::cout <<num*(count/10)-n  << '\n';

  return 0;
}
