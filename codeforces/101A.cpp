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

bool mycompare(pair<int, int> a, pair<int, int> b){
    return b.ss>a.ss;
}

int main(){
      string str;
      int k;
      cin>>str>>k;
      int res = 0;
      vector<pair<int, int>> freq(26, {0,0});
      rep(i, 0, 26){
            freq[i].ff = i;
      }
      rep(i, 0, str.size()){
            freq[str[i] - 'a'].ss++;
      }
      rep(i, 0, 26){
          if(freq[i].ss>0) res++;
      }
      sort(freq.begin(), freq.end(), mycompare);

      vi rem(26, 0);
      rep(i, 0, 26){
            if(freq[i].ss<=k && freq[i].ss>0){
                  rem[freq[i].ff] = 1;
                  k-= freq[i].ss;
                  res--;
            }
      }
      cout<<res<<endl;
      rep(i, 0, str.size()){
            if(rem[str[i] - 'a'] == 0){
                  cout<<str[i];
            }
      }
}
