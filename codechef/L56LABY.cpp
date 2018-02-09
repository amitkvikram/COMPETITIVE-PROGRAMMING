#include <bits/stdc++.h>
using namespace std;

typedef std::vector<int> vi;
typedef long long ll;
typedef vector< vector<int> > vv;
typedef vector< vector<bool> > v_vis;
typedef vector< vector< pair<bool, int> > > vpp;

class Point{
public:
      int x;
      int y;
};

class queueNode{
public:
      Point pt;  // The cordinates of a cell
      int dist;  // cell's distance of from the source
};


int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

bool isValid(vv &v, int row, int col, int n, int m){
      if((row>=0) && (row<n) && (col>=0) && (col<m)){
            if(v[row][col]!=-1) return true;
            else return false;
      }
      else return false;
}

void set_unvisited(v_vis &visited, int n, int m){
      for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                  visited[i][j] = false;
            }
      }
}

int bfs(vv &v, v_vis &visited, vpp &time, Point pt, int n, int m){
      queue<queueNode> q;
      std::vector< std::vector<Point> > v_bfs(n, std::vector<Point>(m, {0,0}));
      Point src = pt;
      queueNode s = {pt, 0};
      q.push(s);
      visited[pt.x][pt.y] = true;
      while(!q.empty()){
            queueNode curr = q.front();
            q.pop();
            Point pt = curr.pt;
            if(v[pt.x][pt.y]>0 && curr.dist<=v[pt.x][pt.y]) {
                  int t = curr.dist;
                  while(pt.x!=src.x || pt.y != src.y){
                        time[pt.x][pt.y].first = true;
                        time[pt.x][pt.y].second = t;
                        pt = v_bfs[pt.x][pt.y];
                        t--;
                  }
                  return curr.dist;
            }
            if(time[pt.x][pt.y].first == true && curr.dist+time[pt.x][pt.y].second<=v[pt.x][pt.y]) return curr.dist+time[pt.x][pt.y].second;

            for(int i =0; i<4; i++){
                  int row = pt.x + rowNum[i];
                  int col = pt.y + colNum[i];
                  if(isValid(v, row, col, n, m) && !visited[row][col]){
                        visited[row][col] = true;
                        v_bfs[row][col] =  pt;
                        queueNode tmp = {{row, col}, curr.dist+1};
                        q.push(tmp);
                  }
            }
      }

      return -1;
}

int main(int argc, char const *argv[]) {
      int t;
      cin>>t;
      while(t--){
            int n, m;
            cin>>n>>m;

            std::vector< vector<int> > v(n, vector<int>(m, 0));
            std::vector< vector<bool> > visited(n, vector<bool>(m, false));
            std::vector< vector< pair<bool, int> > > time(n, vector< pair<bool, int> >(m, make_pair(false, 0)));
            for(int i =0; i<n; i++){
                  for(int j =0; j<m; j++){
                        cin>>v[i][j];
                  }
            }
            Point pt;
            for(int i =0; i<n; i++){
                  for(int j =0; j<m; j++){
                        pt.x = i;
                        pt.y = j;
                        if(v[i][j]==-1){
                              time[i][j].second = -1;
                              time[i][j].first = false;
                              continue;
                        }
                        else if(time[i][j].first == true) continue;
                        int temp = bfs(v, visited, time, pt, n, m);
                        if(temp>=0){
                              time[i][j].first = true;
                              time[i][j].second = temp;
                        }
                        set_unvisited(visited, n, m);
                  }
            }

            for(int i = 0; i<n; i++){
                  for(int j =0; j<m; j++){
                        if(time[i][j].first == false){
                              if(time[i][j].second == -1) cout<<'B';
                              else cout<<'N';
                        }
                        else cout<<'Y';
                  }
                  cout<<endl;
            }

      }
      return 0;
}
