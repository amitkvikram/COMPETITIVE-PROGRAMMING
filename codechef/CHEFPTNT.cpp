#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector< std::vector<int> > vvi;

int main(int argc, char const *argv[]) {
      ll t;
      cin>>t;
      while(t--){
            ll n, m, x, k;
            cin>>n>>m>>x>>k;
            string s;
            cin>>s;
            ll odd_month = (m)/2+(m%2), even_month = (m/2);
            ll odd_workers = 0, even_workers = 0;
            for(ll i =0; i<s.size(); i++){
                  if(s[i] == 'E') even_workers++;
                  else odd_workers++;
            }
            ll max_odd_patent = (x*odd_month<odd_workers)?(x*odd_month):odd_workers;
            ll max_even_patent = (x*even_month<even_workers)?(x*even_month):even_workers;

            if(n<=max_odd_patent+max_even_patent) cout<<"yes"<<endl;
            else cout<<"no"<<endl;
      }
      return 0;
}
