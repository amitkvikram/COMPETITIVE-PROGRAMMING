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
      string s;
      cin>>s;
      int Max = 0;
      rep(i, 0, s.size()){
            rep(j, 1, s.size()+1){
                  string str = s.substr(i, j);
                  size_t npos = s.find(str, i+1);
                  if(npos!=string::npos){
                        if(j>Max) Max = j;
                  }
            }
      }
      cout<<Max<<endl;
}
