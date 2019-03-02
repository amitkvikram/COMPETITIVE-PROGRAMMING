#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
#define ff first
#define ss second 
const int inf = 1e9+10;

int row_num[] = {-1, 1, 0, 0};
int col_num[] = {0, 0, -1, 1};
char Move[] = {'U', 'D', 'L', 'R'};

int n, m, r, c, x, y, row, col;

class pqNode{
    public:
    int left_move;
    int right_move;
    ii coord;
    pqNode(int left_move1, int right_move1, ii coord1){
        left_move = left_move1;
        right_move = right_move1;
        coord = coord1;
    }
    pqNode(){}
};

class myCompare{
    public:
    bool operator()(const pqNode &p1, const pqNode &p2){
        return p1.left_move+ p1.right_move > p2.left_move + p2.right_move;
    }
};

bool check(int i, int j, int n, int m){
    return i >= 0 && j >= 0 && i < n && j < m;
}

int main(){
    cin>>n>>m>>r>>c>>x>>y;
    r--; c--;
    vector<vector<char>> v(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> dist(n, vector<int>(m, inf));
    // vector<vector<ii>> moves(n, vector<ii>(m, {inf, inf}));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>v[i][j];
        }
    }

    deque<ii> q;
    q.push_back({r, c});
    dist[r][c] = 0;

    while(!q.empty()){
        ii curr = q.front();
        q.pop_front();

        for(int i = 0; i< 4; i++){
            row = curr.ff + row_num[i];
            col = curr.ss + col_num[i];

            if(!check(row, col, n, m) || v[row][col] == '*'){
                continue;
            }

            int wt = 0;
            if(Move[i] == 'L'){
                wt++;
            }

            if(dist[curr.ff][curr.ss] + wt < dist[row][col]){
                dist[row][col] = dist[curr.ff][curr.ss] + wt;
                if(wt == 0){
                    q.push_front({row, col});
                }
                else q.push_back({row, col});
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i< n; i++){
        for(int j = 0; j < m; j++){
            // cout<<"("<<moves[i][j].first<<","<<moves[i][j].second<<") ";
            if(dist[i][j] <= x  && dist[i][j] + j - c <= y){
                cnt++;
            }
        }
        // cout<<endl;
    }

    cout<<cnt<<endl;
}