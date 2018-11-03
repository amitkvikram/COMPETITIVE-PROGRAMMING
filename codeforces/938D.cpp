#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ff first
#define ss second
typedef pair< ll, ll > ii;
#define rep(i, a, b) for(ll i =a; i<b; i++)
#define pb push_back
typedef std::vector<ll> vi;

int main(){
      int n, m;
      cin>>n>>m;
      vector<ii> v[n];
      ll a, b, w;
      rep(i, 0, m){
            cin>>a>>b>>w;
            a--; b--;
            v[a].pb({b, w});
            v[b].pb({a, w});
      }

      vi arr(n);
      priority_queue< ii, vector<ii>, greater<ii> > PQ;
      rep(i, 0, n){
            cin>>arr[i];
            PQ.push({arr[i], i});
      }

      while(!PQ.empty()){
            ii t = PQ.top();
            PQ.pop();
            ll cost = t.ff;
            ll ind = t.ss;
            if(arr[ind]!=cost) continue;
            for(auto i:v[ind]){
                  if(cost+(2*i.ss)<arr[i.ff]){
                        arr[i.ff] = cost+(2*i.ss);
                        PQ.push({arr[i.ff], i.ff});
                  }
            }
      }
      for(auto i:arr){
            cout<<i<<' ';
      }
}
