#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[]) {
      string str;
      cin>>str;

      int flag =1;
      for(int i=1; i<str.size(); i++){
            if(str[i] != toupper(str[i])) flag =0;
      }

      if(flag ==1){
            if(str[0] == toupper(str[0])) str[0] = tolower(str[0]);
            else str[0] = toupper(str[0]);

            for(int i=1; i<str.size(); i++){
                  str[i] = tolower(str[i]);
            }
      }

      cout<<str;
      return 0;
}
