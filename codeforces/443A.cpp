#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  string str;
  getline(cin, str);

  int n = str.size();
  std::vector<int> v(26,0);
  if(n<3){
    cout<<0;
    return 0;
  }
  for(int i=1; i<n; i+=3){
    v[tolower(str[i]) - 'a'] = 1;
  }

  int num =0;
  for(int i =0; i<26 ; i++){
    if(v[i]==1) num++;
  }

  cout<<num;

  return 0;
}
