#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[]) {
      string str1, str2;
      cin>>str1>>str2;
      if(str1.size()!=str2.size()){
            cout<<"NO";
            return 0;
      }

      int flag =0;

      for(int i=0; i<str1.size(); i++){
            if(str1[i]!= str2[str1.size()-1-i]){
                  flag=1;
                  break;
            }
      }

      if(flag ==1) cout<<"NO";
      else cout<<"YES";
      return 0;
}
