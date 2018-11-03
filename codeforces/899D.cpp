#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<ll> vi;
typedef pair< string,vi> pr;
#define rep(i, a, b) for(ll i =a; i<b; i++)

int main(int argc, char const *argv[]) {
  int n, m, k;
  cin>>n>>m>>k;
  vi v(n);
  vi is(1000001, 0);
  rep(i, 0, n){
        cin>>v[i];
        is[v[i]]= 1;
 }

int cnt = 0;
vi tmp;
 rep(i, 1, 1e6+1){
       if(is[i] == 1){
            tmp.pb(i);
       }
       if(tmp.front() - tmp.back() + 1 > m){
            tmp.pop_back();
       }
       else if(tmp.size()<=k){
             cnt++;
             tmp.pop_back();
       }
 }

 cout<<cnt<<endl;

  return 0;
}
