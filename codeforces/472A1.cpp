#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef std::vector<int> vi;

int isPrime(int n){
  if(n==2) return 1;
  else if(n%2==0) return 0;
  else{
    for(int i =3; i<=sqrt(n); i+=2){
      if(n%i==0){
        return 0;
      }
    }
  }

  return 1;
}

int main(int argc, char const *argv[]) {

  int num;
  cin>>num;
  int x = 4, y= num-4;
  while(isPrime(y)){
    x+=2;
    y-=2;
  }

  cout<<x<<' '<<y;
  return 0;
}
