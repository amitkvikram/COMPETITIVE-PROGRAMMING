#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ff first
#define ss second
typedef pair< ll, ll > ii;
#define rep(i, a, b) for(ll i =a; i<b; i++)
#define pb push_back
typedef std::vector<ll> vi;
const ll mod = 1000000007;               //1e9+7

ll rowNum[] = {-1, 0, 0, 1};
ll colNum[] = {0, -1, 1, 0};

int main(){
      int n, k;
      cin>>n>>k;
      string s, t;
      cin>>s;

      vi v(26, 0);
      int ind = 27, ind1 = 0;
      for(int i =0; i<s.size(); i++){
            v[s[i] - 'a'] = 1;
            if((s[i] - 'a') < ind) ind = s[i] - 'a';
            if(s[i] - 'a' > ind1) ind1 = s[i] - 'a';
       }

      if(k>n){
            t = s;
            rep(i, n, k){
                  t.push_back(v[ind] + 'a');
            }
      }

      else{
            for(int i = k-1; i>=0; i--){
                  if(s[i] != v[ind1]+'a'){
                        for(int j =0; j<ind1; j++){
                              t.push_back(s[j]);
                        }
                        t.push_back(s[ind1]);
                        for(int j = ind1+1; j<k; j++){
                              j.push_back(v[ind] + 'a');
                        }
                  }
            }
      }


      cout<<t<<endl;
}
