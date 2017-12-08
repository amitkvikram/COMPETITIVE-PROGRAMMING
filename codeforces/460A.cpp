#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int n1,m;
  cin>>n1>>m;
  int n= 0;
  while((n1/m)-n){
    int temp = n1;
    n1+=((n1/m)-n);
    n = temp/m;
  }

  cout<<n1;
  return 0;
}
