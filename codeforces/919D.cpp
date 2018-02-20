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
      bool visited = false;
      int parent = -1;
      vi adj;
      vi cnt;
      int in_degree = 0;
    graphNode():cnt(26, 0){}
};

void func1(auto &v, int n, string &str){
      int Max = 0;
      queue<ll> q;
      rep(i, 0, n){
            if(v[i].in_degree == 0){
                  q.push(i);
            }
      }

      while(!q.empty()){
            ll tmp = q.front();
            q.pop();
            v[tmp].visited = true;
            for(auto it = v[tmp].adj.begin(); it!=v[tmp].adj.end(); it++){
                  if(v[*it].visited == true) continue;
                  v[*it].in_degree -=1;
                  (v[*it].cnt)[str[tmp] - 'a']++;
                  if((v[*it].cnt)[str[tmp] - 'a'] > Max) Max = v[*it].cnt[str[tmp] - 'a'];
                  if(v[*it].in_degree == 0){
                        q.push(*it);
                  }
            }
      }
      cout<<Max<<endl;
}

int main(int argc, char const *argv[]) {
      int n, m;
      cin>>n>>m;
      string str;
      cin>>str;
      int a, b;
      vector<graphNode> v(n);
      for(int i =0; i<m; i++){
            cin>>a>>b;
            v[a].adj.push_back(b);
            v[b].in_degree++;
      }

      func1(v, n, str);

      return 0;
}
