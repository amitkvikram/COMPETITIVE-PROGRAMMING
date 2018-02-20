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

class graphNode{
    public:
      int parent;
      int sz;
};

void make_set(auto &v, int n){
      rep(i, 0, 26){
            v[i].parent = i;
            v[i].sz = 1;
      }
}

int find(auto &v, int u){
      while(v[u].parent!=u){
            u = v[u].parent;
      }
      return u;
}

void union1(auto &v, int u1, int u2){
      int x = find(v, u1);
      int y = find(v, u2);
      if(v[x].sz < v[y].sz){
            v[x].parent = y;
            v[y].sz+=v[x].sz;
      }
      else{
            v[y].parent = x;
            v[x].sz += v[y].sz;
      }
}

int main(){
      int n;
      cin>>n;
      string s1, s2;
      cin>>s1>>s2;
      std::vector<graphNode> v(26);
      make_set(v, n);

      rep(i, 0, n){
            if(s1[i]!=s2[i]){
                  int u1 = s1[i]- 'a';
                  int u2 = s2[i] - 'a';
                  if(find(v, u1) != find(v, u2)){
                        union1(v, u1, u2);
                  }
            }
      }

      int res =0;
      list<pair<char, char>> pq;

      rep(i, 0, 26){
            if(v[i].parent == i){
                  res+= v[i].sz - 1;
            }
            else{
                  pq.push_back({'a'+i, 'a' + find(v, (int)i)});
            }
      }

      cout<<res<<endl;
      for(auto i: pq){
            cout<<i.ff<<' '<<i.ss<<endl;
      }
}
