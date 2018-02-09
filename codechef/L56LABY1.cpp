#include <bits/stdc++.h>
using namespace std;

typedef std::vector<int> vi;
typedef long long ll;
typedef vector< vector<int> > vv;
typedef vector< vector<bool> > v_vis;
typedef vector< vector<char> > vpp;

class Point{
public:
      int x;
      int y;
};

class queueNode{
public:
      Point pt;  // The cordinates of a cell
};


int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

bool compare(pair<Point,int> a, pair<Point,int> b){
      return a.second>b.second;
}

bool isValid(vv &v, int row, int col, int n, int m){
      if((row>=0) && (row<n) && (col>=0) && (col<m)){
            if(v[row][col]!=-1) return true;
            else return false;
      }
      else return false;
}

void bfs(vv &v, v_vis &visited, vpp &v1, int n, int m, queue<queueNode> &q){
      while(!q.empty()){
            queueNode curr = q.front();
            q.pop();
            Point pt = curr.pt;

            visited[pt.x][pt.y]= false;
            for(int i =0; i<4; i++){
                  int row = pt.x + rowNum[i];
                  int col = pt.y + colNum[i];
                  if(isValid(v, row, col, n, m) ){
                      if(v[pt.x][pt.y] - 1>v[row][col]){
                          v1[row][col]= 'Y';
                          v[row][col] = v[pt.x][pt.y] - 1;
                          if(visited[row][col]== false){
                              q.push((queueNode){row, col});
                              visited[row][col]= true;
                          }
                      }
                      else if(v[pt.x][pt.y] -1 == v[row][col]){
                          v1[row][col] = 'Y';
                      }
                  }
            }
      }
}

int main(int argc, char const *argv[]) {
      int t;
      cin>>t;
      while(t--){
            int n, m;
            cin>>n>>m;

            std::vector< vector<int> > v(n, vector<int>(m, 0));
            std::vector< pair<Point,int> > exits;
            std::vector< vector<bool> > visited(n, vector<bool>(m, false));
            std::vector< vector<char> > v1(n, vector<char>(m, 'N'));
            queue<queueNode> q;
            for(int i =0; i<n; i++){
                  for(int j =0; j<m; j++){
                        cin>>v[i][j];
                        if(v[i][j]>0){
                              exits.push_back({{i,j},v[i][j]});
                              v1[i][j] = 'Y';
                              visited[i][j] = true;
                        }
                        else if(v[i][j]==-1){
                            v1[i][j] = 'B';
                        }
                  }
            }

            sort(exits.begin(), exits.end(),compare);
            for(int i =0; i<exits.size();i++){
                  queueNode tmp;
                  tmp.pt = exits[i].first;
                  q.push(tmp);
            }
            bfs(v, visited, v1, n, m , q);

            for(int i = 0; i<n; i++){
                  for(int j =0; j<m; j++){
                        cout<<v1[i][j];
                  }
                  cout<<endl;
            }
      }
      return 0;
}
