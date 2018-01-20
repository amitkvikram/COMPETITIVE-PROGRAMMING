#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  ll n;
  cin>>n;
  string str;
  cin>>str;
  ll cnt = 0;
  vi v1(26, 0);
  n = str.size();
  for(int i =0; i<n; i++){
    if(i%2){
      if(v1[tolower(str[i])-'a']>0) v1[tolower(str[i])-'a']--;
      else cnt++;
    }
    else{
      v1[tolower(str[i])-'a']++;
    }
  }

  cout<<cnt;
  return 0;
}
