#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int GCD(int a, int b){
  if(b == 0) return a;
  GCD(b, a%b);
}

int main(int argc, char const *argv[]) {
  int a, b, n;
  cin>>a>>b>>n;
  int flag= 0, temp, cur; //0 represents the player who starts the game
  while(1){
    if(flag == 0) cur = a;
    else cur = b;
    if(cur >n) temp = GCD(cur,n);
    else temp = GCD(n, cur);
    if(temp > n){
      cout<<!flag;
      break;
    }

    else{
      n-=temp;
      flag = !flag;
    }
  }
  return 0;
}
