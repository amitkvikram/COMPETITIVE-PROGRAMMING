#include <bits/stdc++.h>

using namespace std;
#define REP(i,a,b) for(int i=a; i<n; i++)


int max1(int a,int b){
  int max;
  (a>b) ?(max=a) :(max=b);
  return max;
}

int main(int argc, char const *argv[]) {
  int n,k;
  cin>>n>>k;
  int temp,sum=0;
  REP(i, 0, n){
    cin>>temp;
    sum+=temp;
  }

  temp=(2*k*n-n-2*sum);
  int count=max1(0,temp);
  cout<<count<<'\n';


  return 0;
}
