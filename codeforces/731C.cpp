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

graphNode{
      ll parent;
      int color;
      list<int> adj;
      bool visited = false;
}

int main(){
      int n, m, k;
      cin>>n>>m>>k;
      int c;
      rep(i, 0, n){
            cin>>c;
            c--;
            v[i].color = c;
      }

      std::vector<graphNode> v(n);
      int l, r;
      rep(i, 0, m){
            cin>>l>>r;
            l--; r--;
            v[l].adj.pb(r);
            v[r].adj.pb(l);
      }

      ll res = 0;
      rep(i, 0, n){
            if(v[i].visited == false){
                  v[i].visited = true;
                  std::vector<int> color;
                  color.pb(v[i].color);
                  queue<int> q;
                  q.push(i);
                  while(!q.empty()){
                        int tmp = q.front();
                        q.pop();
                        for(auto it:v[tmp].adj){
                              if(v[it].visited == false){
                                    q.push(tmp);
                                    color.pb(tmp);
                              }
                        }
                  }

                  int Max = 0;
                  color.sort();

                  int curr = 0;
                  int c_c, c_m = 0;
                  for(int i =0; i<color.size(); i++){

                        if(color[i] == c_m){
                              curr++;
                        }
                        else{
                              curr = 1;
                        }

                        if(curr > Max){
                              Max = curr;
                        }
                  }

                  res+=color.size - Max;
            }
      }
      cout<<res<<endl;
}
