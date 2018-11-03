#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ff first
#define ss second
typedef pair< ll, ll > ii;
#define rep(i, a, b) for(ll i =a; i<b; i++)
#define pb push_back
typedef std::vector<ll> vi;
const int mod = 1000000007;               //1e9+7

int main(){
      string s;
      cin>>s;
      cnt = 0;
      rep(i, 0, n){
            if(s[i] <= 'a'+cnt){
                  cnt++;
            }
            if(cnt == 26) break;
      }

      if(cnt == 26){
            cout<<s<<endl;
      }
      else cout<<"-1\n";
}
