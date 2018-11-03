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

bool mycompare(auto a, auto b){
      return a.ss<b.ss;
}

int main(){
      int n;
      cin>>n;
      vector<pair<int , int>> v(n);
      rep(i, 0, n){
            cin>>v[i].ss;
            v[i].ff = i;
      }
      string s;
      cin>>s;
      std::vector<ii> v1 = v;
      sort(v.begin(), v.end(), mycompare);
      int flag = 0, Max = -1;
      rep(i, 0, n){
            Max = max(v[i].ss, Max);
            if(v[i].ss  < Max){
                  if(s[i]=='0'){
                        flag = 1;
                        break;
                  }
            }
      }

      if(flag == 1){
            cout<<"YES\n";
      }
      else cout<"NO\n";
}
