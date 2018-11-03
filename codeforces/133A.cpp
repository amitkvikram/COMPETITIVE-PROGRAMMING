#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[]) {
      string str;
      cin>>str;
      int flag =0;
      for(int i=0; i<str.size(); i++){
            if(str[i] == 'H' || str[i] == 'Q' || str[i] == '9'){
                  flag =1;
            }
      }

      if(flag ==1) cout<<"YES";
      else std::cout << "NO";
      return 0;
}
