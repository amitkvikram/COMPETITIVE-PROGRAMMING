//A   VICIOUS KEYBOARD

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> v;

int main(int argc, char const *argv[]) {
  char str[101];

  std::cin >> str;
  //std::cout << str << '\n';
  int len=strlen(str),count=0,k=1;

  if(len==1) {
    cout<<'0'<<'\n';
  }
  else{
  for(int i=0;i<len-1;){

  if (str[i]=='V'&& str[i+1]=='K') {

    count++;
    i+=2;
  }
  else if ((str[i]=='V'&& str[i+2]!='K') || str[i+1]=='K' ) {
    if(k){
    count++;
    i+=2;
    k--;
    }

    else{
        i+=1;
    }

  }

  else{
    i+=1;
  }

  }
  std::cout << count << '\n';
}


  return 0;
}
