#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[]) {
      int n, t;
      cin>>n>>t;

      string str;
      cin>>str;
      for(int j =0; j<t; j++){
            for(int i=1; i<n; i++){
                  if(str[i] =='G' && str[i-1] =='B'){
                        str[i]='B';
                        str[i-1]='G';
                        i++;
                  }
            }
      }
      cout<<str;
      return 0;
}
