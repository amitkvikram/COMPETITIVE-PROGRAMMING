#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  string s1, s2;
  cin>>s1>>s2;
  int s = s1.size();
  for(int i =0; i<s; i++){
    (s1[i]!=s2[i])?cout<<1:cout<<0;
  }
  return 0;
}
