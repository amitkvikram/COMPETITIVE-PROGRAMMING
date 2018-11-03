#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  int n, m;
  cin>>n>>m;
  int day = 0;

  while(n){ //loop breks when vasya runs out of shoes
    day++;
    if(day%m==0) continue;
    n--;
  }

  cout<<day;
  return 0;
}
