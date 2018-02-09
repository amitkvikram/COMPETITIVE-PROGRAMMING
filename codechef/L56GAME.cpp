#include <bits/stdc++.h>
using namespace std;

typedef std::vector<int> vi;
typedef long long ll;

int main(int argc, char const *argv[]) {
      int t;
      cin>>t;
      while(t--){
            int n;
            cin>>n;
            vi v(n);
            for(int i =0; i<n; i++){
                  cin>>v[i];
            }
            int num_odd = 0, num_even = 0;
            for(int i  =0; i<n; i++){
                  if(v[i]%2==0) num_even++;
                  else num_odd++;
            }

            int n1 = num_odd%2;
            if(n1==1) cout<<"2"<<endl;
            else cout<<"1"<<endl;

      }
      return 0;
}
