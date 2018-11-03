#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ff first
#define ss second
typedef pair< int , int > ii;
#define rep(i, a, b) for(int i =a; i<b; i++)
#define pb push_back
typedef std::vector<int> vi;
const ll mod = 1000000007;               //1e9+7

int maim(){
      int n;
      cin>>n;
      vi v(n);
      std::vector<ii> tmp;
      int Sum = 0;
      rep(i, 0, n){
            int flag = 0;
            cin>>v[i];
            for(auto &j:tmp){
                  if(j.ff==v[i]){
                        j.ss++;
                        flag = 1;
                  }
            }
            if(flag == 0){
                  tmp.pb({v[i], 1});
            }
            Sum+=v[i];
      }

      int Min = min_element(v.begin(), v.end());
      int Max = max_element(v.begin(), v.end());

      rep(i, Min, Max+1){
            int flag = 0;
            for(auto j:tmp){
                  if(j.ff =)
            }
      }
}
