#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  int n, h;
  cin>>n>>h;
  int wd = 0,temp;
  for(int i =0; i<n; i++){
    cin>>temp;
    if(temp>h) wd+=2;
    else wd+=1;
  }

  cout<<wd;
  return 0;
}
