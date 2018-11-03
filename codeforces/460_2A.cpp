#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector< std::vector<int> > vvi;

int main(int argc, char const *argv[]) {
      double err = 1e-7;
      double n, m, a, b, price = 1000.0;
      cin>>n>>m;
      for(int i =0; i<n; i++){
            cin>>a>>b;
            if(price - (a/b)>err){
                  price = a/b;
            }
      }
      cout<<std::setprecision(8)<<price*m<<endl;
      return 0;
}
