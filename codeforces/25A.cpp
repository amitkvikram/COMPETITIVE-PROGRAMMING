#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  int n;
  int odd_n = 0, evn_n = 0;
  int temp1, temp2, temp;

  cin>>n;
  for(int i =0; i<n; i++){
    cin>>temp;
    if(temp%2){
      odd_n++;
      if(odd_n==1) temp1=i+1;
    }
    else{
      evn_n++;
      if(evn_n==1) temp2=i+1;
    }
  }
  if(odd_n == 1)  cout<<temp1;
  else cout<<temp2;
  return 0;
}
