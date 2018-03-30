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

vi row_num = {-1, 0, 1, 0, -1, 1, -1, 1};
vi col_num = {0,-1, 0, 1 -1, -1, 1, 1};
vector<string> move = {'U', 'L', 'R', 'D', "LU", "RU", "LD", "RD"};

class pt{
public:
      int x;
      int y;
}

bool check(int i, j){
      return i<8 && j<8 && i>=0 && j>=0;
}

class graphNode{
public:
      int collapse = 0;
      int len_train = 0;
      int len_road = 0;
      int t_train = 0;
      int t_ road = 0;
      bool visited_train = false;
      bool visited_road = false;
      int parent = -1;
};

void dfs(auto &adjmat, auto &v, int src, int n){
      v[src].visited = true;
      rep(i, 0, n){
            if(adjmat[src][i] == 1 && v[i].visited == false){

            }
      }
}

int main(){
      int n, m;
      cin>>n>>m;

      std::vector<std::vector<graphNode>> adjmat(n, std::vector<int>(n, 0));

      int a, b;
      rep(i, 0, m){
            cin>>a>>b;
            adjmat[a][b] = 1;
            adjmat[b][a] = 1;
      }

      queue<int> q;
      q.push(0);
      v[0].visited = true;
      while(!q.empty()){
            int tmp = q.front();
            q.pop();

            rep(i, 0, n){
                  if(adjmat[src][i] == 1){
                        v[i].len_train = v[src].len-train + 1;
                        v[i].visited_train = true;
                  }
                  else{
                        v[i].len_road = v[src].len_road + 1;
                        v[i].visited_road = true;
                        if(v[])
                  }
            }
      }

}
