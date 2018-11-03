#include "bits/stdc++.h"

using namespace std;

bool compare(int a, int b){
      return a>b;
}

int main(int argc, char const *argv[]) {
      int n, m;
      cin>>n>>m;
      std::vector<int> v(m);

      for(int i=0; i<m; i++){
            cin>>v[i];
      }

      sort(v.begin(), v.end(), compare);
      int min = 10000;
      for(int i=0; i<m-n+1; i++){
            if(v[i]-v[i+n-1] <min) min = v[i]-v[i+n-1];
      }

      cout<<min;
      return 0;
}
