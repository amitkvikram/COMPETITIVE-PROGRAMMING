#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  string str1, str2, str;
  cin>>str1>>str2>>str;

  vi v(26, 0);
  int n1 = str1.size(), n2 = str2.size(), n = str.size();
  for(int i = 0; i<n1; i++ ){
    v[str1[i] - 'A']++;
  }

  for(int i =0 ; i<n2; i++){
    v[str2[i] - 'A']++;
  }

  for(int i =0; i<n; i++){
    v[str[i] - 'A']--;
  }

  int cnt = 0;
  for(int i =0; i<26; i++){
    if(v[i] == 0) cnt++;
  }

  if(cnt == 26) cout<<"YES";
  else cout<<"NO";

  return 0;
}
