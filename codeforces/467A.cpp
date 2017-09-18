#include "bits/stdc++.h"

using namespace std;
int main(int argc, char const *argv[]) {
      int n;
      cin>>n;
      int count =0, a, b;

      for(int i =0; i<n; i++){
            cin>>a>>b;
            if(b - a>1){
                  count++;
            }

      }

      cout<<count;
      return 0;
}
