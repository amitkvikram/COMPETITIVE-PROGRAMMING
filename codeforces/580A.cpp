#include "bits/stdc++.h"

using namespace std;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
      int n;
      cin>>n;

      vi v(n);
      int temp=0, max =0, count=0;
      for(int i=0; i<n; i++){
            cin>>v[i];
            if(v[i]>=temp){
                  count++;
                  temp = v[i];
            }
            else{
                  if(count>=max) max = count;
                  temp = v[i];
                  count=1;
            }
      }
      if(count>=max) max = count;
      cout<<max;
      return 0;
}
