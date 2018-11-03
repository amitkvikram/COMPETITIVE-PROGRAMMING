#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[]) {
      string str;
      cin>>str;

      int n= str.size();

      string str1 = "WUB";
      int found =0;
      int flag =0;
      for(int i=0; i<str.size(); i++){
            if(str[i]==str1[0]){
                  found = 0;
                  for(int j=0; j<3 && i+j<str.size(); j++){
                        if(str[i+j] == str1[j]) found++;
                  }

                if(flag == 1 && found==3) flag =2;
            }

            if(found ==3){
                  for(int j=0; j<3; j++){
                        str.erase(str.begin()+i);
                  }
                  found=0;
                  i-=1;
            }

            else{
                    if(flag==0){
                        flag =1;
                    }
                      else if(flag ==2){
                          str.insert(str.begin()+i,1,' ');
                          flag=1;
                          i++;
                      }
            }

      }

      cout<<str;

      return 0;
}
