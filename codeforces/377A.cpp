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

bool check(int x, int y, int n, int m){
      return x<n && y<m &&x>=0 && y>=0;
}

class pt{
public:
      int x;
      int y;
};

int main(){
      int n, m, k;
      cin>>n>>m>>k;
      vector<std::vector<char>> v(n, std::vector<char> (m));
      queue<pt> q;
      std::vector<std::vector<int>> degree(n, std::vector<int> (m, 0));
      queue<pt> q_rev;
      std::vector<std::vector<bool> > visited(n, std::vector<bool> (m, false));

      rep(i, 0, n){
            rep(j, 0, m){
                  cin>>v[i][j];
                  if(q.empty() && v[i][j] == '.'){
                        q.push({i, j});
                        visited[i][j] = true;
                  }
            }
      }
      vector<std::vector<pt>> parent(n, std::vector<pt> (m, q.front()));
      while(!q.empty()){
            pt t = q.front();
            q.pop();
            int x = t.x; int y = t.y;
            int flag = 0;
            rep(i, 0, 4){
                  int x1 = x+row_num[i]; int y1 = y+col_num[i];
                  if(!check(x1, y1, n, m)) continue;
                  if(v[x1][y1] == '.' && visited[x1][y1] == false){
                        visited[x1][y1] = true;
                        flag = 1;
                        degree[x][y]++;
                        parent[x1][y1] = {x, y};
                        q.push({x1, y1});
                  }
            }

            if(flag == 0){
                  q_rev.push({x, y});
            }
      }

      int cnt = 0;
      while(!q_rev.empty()){
            if(cnt == k) break;
            pt t = q_rev.front();
            q_rev.pop();
            int x = t.x; int y = t.y;
            v[x][y] = 'X';
            cnt++;
            t = parent[x][y];
            degree[t.x][t.y]--;
            if(degree[t.x][t.y] == 0){
                  q_rev.push({t.x, t.y});
            }
      }
      rep(i,0, n){
            rep(j, 0, m){
                  cout<<v[i][j];
            }
            cout<<endl;
      }

      return 0;
}
