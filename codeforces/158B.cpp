#include "bits/stdc++.h"

using namespace std;
typedef std::vector<int> vi;

bool compare(int a, int b){
      return a>b;
}

int main(int argc, char const *argv[]) {
      int n;
      cin>>n;

      vi v(n);
      vi num(5,0);

      for(int i=0; i<n; i++){
            cin>>v[i];
      }

      sort(v.begin(), v.end(), compare);

      int space = 0, count=0;

      for(int i=0;i<n ; i++){
            if(num[4-v[i]] >0){
                  num[4-v[i]]--;
            }

            else if(3-v[i] > 0 && num[3- v[i]] >0){
                  num[3-v[i]]--;
                  num[3]++;
            }
            else if(2-v[i]> 0 && num[2-v[i]] > 0){
                  num[2-v[i]]--;;
                  num[2]++;
            }

            else {
                  count++;
                  num[v[i]]++;
            }
      }

      cout<<count;
      return 0;
}
