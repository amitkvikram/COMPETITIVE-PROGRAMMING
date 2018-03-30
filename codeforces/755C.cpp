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
      int n;
      cin>>n;
      vi p(n);

      int res = 0;
      vi cnt(n, 0);
      rep(i, 0, n){
            cin>>p[i];
            p[i]--;
            if(p[i] == i) res++;
            else cnt[i] = 1;
      }

      int count = 0;
      rep(i, 0, n){
            if(cnt[i] == 1) count++;
      }
      res+=count/2;
      cout<<res<<endl;
}
