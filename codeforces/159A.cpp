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

int main(){
      int n, d;
      cin>>n>>d;
      std::vector<pair<pair<string, string>, int>> v(n);
      rep(i,0, n){
            cin>>v[i].ff.ff>>v[i].ff.ss>>v[i].ss;
      }

      int res = 0;
      vector<pair<string, string>> tmp;
      rep(i, 0, n){
            if(v[i].ss>=0){
                  int flag = 0;
                  pair<string, string> curr = {v[i].ff.ss, v[i].ff.ff};
                  pair<string, string> curr1 = {v[i].ff.ff, v[i].ff.ss};
                  rep(j, i+1, n){
                        if(flag == 1 && (v[j].ff == curr || v[j].ff == curr1){
                              v[j].ss = -1;
                        }
                        else if(v[j].ff == curr && v[j].ss-v[i].ss<=d){
                              flag = 1;
                              tmp.pb(curr);
                              v[j].ss = -1;
                        }
                  }
            }
      }
      cout<<tmp.size()<<endl;
      for(auto i:tmp){
            coout<<tmp.ff<<' '<<tmp.ss<<endl;
      }
}
