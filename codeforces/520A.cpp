#include<bits/stdc++.h>
using namespace std;

typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  string str;
  cin>>str;
  vi v(26, 0);
  int s = str.size();
  for(int i =0; i<s; i++){
    v[tolower(str[i]) - 'a']++;
  }

  int cnt = 0;
  for(int i =0; i<26; i++){
    if(v[i]>0) cnt++;
  }

  if(cnt == 26) cout<<"YES";
  else cout<<"NO";
  return 0;
}
