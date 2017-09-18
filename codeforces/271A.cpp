#include "bits/stdc++.h"
using namespace std;

typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
      int k,l,m,n, d;
      cin>>k>>l>>m>>n>>d;

      vi v(d+1, 0);

      for(int i=1; i<d+1; i++){
            if(i%k ==0 || i%l == 0|| i%m==0 || i%n==0){\
                  v[i]=1;
            }
      }

      int count=0;
      for(int i=1; i<d+1; i++){
            if(v[i]==1) count++;
      }
      cout<<count;

      return 0;
}
