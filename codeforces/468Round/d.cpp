#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ff first
#define ss second
typedef pair< int , int > ii;
#define rep(i, a, b) for(int i =a; i<b; i++)
#define pb push_back
typedef std::vector<int> vi;
const ll mod = 1000000007;               //1e9+7

class graphNode{
public:
      list<int> adjList;
      list<int> apple;
      bool visited = false;
      int parent = 0;
      int in_degree = 0;
};

int main(){
      int n;
      cin>>n;
      std::vector<graphNode> v(n);
      int a;
      rep(i, 1, n){
            // cout<<i<<' ';
            cin>>a;
            a--;
            v[i].adjList.pb(a);
            v[i].apple.pb(0);
            v[a].in_degree++;
      }
      v[0].apple.pb(0);
      queue<int> q;
      rep(i, 0, n){
            if(v[i].in_degree == 0){
                   q.push(i);
                   v[i].visited = true;
            }
      }

      while(!q.empty()){
            int ind = q.front();
            q.pop();
            v[ind].apple.sort();
            int curr = v[ind].apple.back(), cnt = 1, res = 0;
              v[ind].apple.pop_back();
              while(v[0].apple.size()){
                    int x = v[0].apple.back();
                    v[0].apple.pop_back();
                    if(x == curr){
                          cnt++;
                    }
                    else{
                          if(cnt%2){
                             res++;
                          }
                          curr = x;
                          cnt = 1;
                    }
              }
            for(auto it = v[ind].adjList.begin(); it!=v[ind].adjList.end(); it++){
                  if(v[(*it)].visited == false){
                         while(v[ind].apple.size()){
                               int l = v[ind].apple.back();
                               v[ind].apple.pop_back();
                               v[*it].apple.pb(l+1);
                         }
                         v[*it].in_degree--;
                       if(v[*it].in_degree == 0){
                           v[(*it)].visited = true;
                           q.push(*it);
                       }
                  }
            }
      }

      v[0].apple.sort();
      int curr = v[0].apple.back(), cnt = 1, res = 0;
      v[0].apple.pop_back();
      while(v[0].apple.size()){
            int x = v[0].apple.back();
            v[0].apple.pop_back();
            if(x == curr){
                  cnt++;
            }
            else{
                  if(cnt%2) res++;
                  curr = x;
                  cnt = 1;
            }
      }
    if(cnt%2) res+=1;
    cout<<res<<endl;
    return 0;
}
