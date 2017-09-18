#include "bits/stdc++.h"
using namespace std;

typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
      int n;
      cin>>n;
      vi v1(n);
      vi v(n);
      for(int i=0; i<n; i++){
            cin>>v[i];
            v1[v[i]-1] = i+1;
      }


      for(int i=0; i<n; i++){
            cout<<v1[i]<<' ';
      }

      return 0;
}
