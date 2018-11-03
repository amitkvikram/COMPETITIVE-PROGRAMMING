#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  string s;
  char c;
  int num =1;
  cin>>s;
  c = s[0];
  for(int i=0; i<n-1; i++){
    cin>>s;
    if(s[1]==c){
      num++;;
      c = s[0];
    }
  }

  cout<<num;
  return 0;
}
