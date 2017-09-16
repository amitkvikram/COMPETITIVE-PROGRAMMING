//MIKE AND PALINDROME
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> v;
#define rep(i,a,b) for(int i=a; i<b; i++)

int main(int argc, char const *argv[]) {
  char str[16];
  std::cin >> str;
  int len=strlen(str),count=0;
  rep(i, 0, len/2){
    if (str[i]!=str[len-1-i]) {
      count++;
    }
  }

  if (count==1) {
    std::cout << "YES" << '\n';
  }
  else if (count==0 && len%2!=0) {
    std::cout << "YES" << '\n';
  }
  else std::cout << "NO" << '\n';

  return 0;
}
