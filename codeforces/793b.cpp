#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ff first
#define ss second
typedef pair< int , int> ii;
#define rep(i, a, b) for(int i =a; i<b; i++)
#define pb push_back
typedef std::vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef vector<viii> viiii;
typedef vector<bool> vb;
typedef vector<vb> vbb;
typedef vector<vbb> vbbb;
typedef vector<vbbb> vbbbb;
const ll mod = 1000000007;               //1e9+7
const int inf = INT_MAX;

ll row_num[] = {-1, 0, 0, 1};
ll col_num[] = {0, -1, 1, 0};
char Move[] = {'U', 'L', 'R', 'D'};
// bool visited[1000][1000][26][3];

int n, m;
ii S, T;

bool check(int i, int j)
{
    return i < n && j < m && i >= 0 && j >= 0;
}

class pt{
    public:
      int x;
      int y;

    pt(int x1, int y1){
        x = x1;
        y = y1;
    }

    pt(){}
};

class State{
    public:
        pt coord;
        char move;
    State(pt coord1, char move1){
        coord = coord1;
        move = move1;
    }

    State(){}
};

class QueueNode{
    public:
        State state;
        int moves;

    QueueNode(State state1, int moves1){
        state = state1;
        moves = moves1;
    }
    QueueNode(){}
}; 

bool dfs(QueueNode &s,  vector<vector<char>> &v){
    if(s.moves > 2){
        return false;
    }

    int x = s.state.coord.x;
    int y = s.state.coord.y;

    if(T.ff == x && T.ss == y){
        return true;
    }

    visited[x][y][s.state.move - 'A'][s.moves] = true;

    rep(i, 0, 4){
        // cout<<"running"<<endl;
        int x1 = x + row_num[i];
        int y1 = y + col_num[i];

        if(!check(x1, y1) || v[x1][y1] == '*'){
            continue;
        }

        int d = s.moves;

        if(Move[i] != s.state.move){
            d++;
        }
        // cout<<Move[i] - 'A'<<endl;
        if(d <=2 && visited[x1][y1][Move[i] - 'A'][d] == false){
            QueueNode nextState = QueueNode(State(pt(x1, y1), Move[i]), d);
            if(dfs(nextState, v)){
                return true;
            }
        }
    }

    return false;
}

// dfs solution 
int main()
{
    cin >> n >> m;

    vector<vector<char>> v(n, vector<char>(m));
    vector<vector<int>> dist(n, vector<int>(m, inf));
    vector<vector<int>> count(n, vector<int>(m, 2000));

    rep(i, 0, n){
        rep(j, 0, m){
            cin >> v[i][j];
            if(v[i][j] == 'S')
                S = make_pair(i, j);
            else if(v[i][j] == 'T')
                T = {i, j};
        }
    }

    // vbbbb visited(n, vbbb(m, vbb(26, vb(3, false))));
    // bool visited[1000][1000][4][3];

    // rep(i, 0, 1000){
    //     rep(j, 0, 1000){
    //         rep(k, 0, 4){
    //             rep(l, 0, 3){
    //                 visited[i][j][k][l] = false;
    //             }
    //         }
    //     }
    // }

    bool res = false;

    rep(i, 0, 4){
        // cout<<"here\n";
        int x = S.ff + row_num[i];
        int y = S.ss + col_num[i];

        if(!check(x, y) || v[x][y] == '*'){
            continue;
        }

        if(visited[x][y][Move[i] - 'A'][0] == false){
            // cout<<"push"<<endl;
            QueueNode currState = QueueNode(State(pt(x, y), Move[i]), 0);
            if(dfs(currState, v)){
                res = true;
                break;
            }
        }
    }


    if(res){
        cout << "YES\n";
    }
    else
        cout << "NO\n";
}