#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  string str;
  cin>>str;
  int n = str.size();
  int low = 0, up = 0;
  for(int i =0;i<n; i++){
    if(islower(str[i])) low++;
    else up++;
  }

  if(up>low){
    for(int i = 0; i<n; i++){
      str[i] = toupper(str[i]);
    }
  }

  else{
    for(int i =0; i<n; i++){
      str[i] = tolower(str[i]);
    }
  }

  cout<<str;

  return 0;
}
