#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ff first
#define ss second
typedef pair< int, int > ii;
#define rep(i, a, b) for(int i =a; i<b; i++)
#define pb push_back
typedef std::vector<int> vi;
const int mod = 1000000007;               //1e9+7

vi row_num = {-1, 0, 1, 0};
vi col_num = {0,-1, 0, 1};

int find(auto &v, int i){
      while(v[i].parent!=i){
            v[i].parent = v[v[i].parent].parent;
            i = v[i].parent;
      }
      return i;
}

void union1(auto &v, int i, int j){
      int a = find(v, i), b = find(v, j);
      if(a!=b){
            if(v[a].sz>v[b].sz){
                  v[b].parent = a;
                  v[a].sz+=v[b].sz;
                  if(v[b].cycle == true) v[a].cycle = true;
            }
            else{
                  v[a].parent = b;
                  v[b].sz+=v[a].sz;
                  if(v[a].cycle == true) v[b].cycle = true;
            }
      }
}

bool connected(auto &v, int i, int j){
      return find(v, i) == find(v, j);
}

class graphNode{
public:
      int parent = -1;
      int sz = 1;
      bool visited = false;
      list<int> adjList;
      bool cycle = false;
};

int main(){
      int n,m;
      cin>>n>>m;
      int a, b;
      std::vector<graphNode> v(n);
      rep(i, 0, n){
            v[i].parent = i;
      }
      rep(i, 0, m){
            cin>>a>>b;
            a--; b--;
            if(connected(v, a, b)){
                  int i = find(v, b);
                  v[i].cycle = true;
            }
            else{
                  union1(v, a, b);
            }
      }

      int res = 0;
      rep(i, 0, n){
            if(v[i].parent == i && v[i].cycle == false) res++;
      }
      cout<<res<<endl;
}
