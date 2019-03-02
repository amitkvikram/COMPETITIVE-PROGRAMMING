#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef long long ll;
const int inf = 1e8;

#define ff first
#define ss second
#define rep(i, a, b) for(int i = a; i<b; i++)
// const ll inf = LLONGs_MAX;

int row_num[] = {0, 0, -1, 1};
int col_num[] = {-1, 1, 0, 0};
char Move[] = {'L', 'R', 'U', 'D'};
// vi a(100);

vi a(100);

ii check1(int i, int j, int n, char move){
    ii temp = {i, j};
    if(move == 'L' || move == 'R'){
        if(j < 0 || j > a[i] - 1){
            temp.ff = -1;
        }
    }

    else{
        if(i > n - 1 || i < 0){
            temp.ff = -1;
        }
        else{
            temp.ss = min(j, a[i] - 1);
        }
    }
    return temp;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin>>n;

    for(int i = 0; i<n; i++){
        cin>>a[i];
        a[i]++;
    }

    queue<ii> q;

    vector<vi> dist(100, vector<int>(1e5 + 2, inf));
    vector<vector<bool>> visited(100, vector<bool>(1e5 + 2, false));

    int r, c, r1, c1;
    cin>>r>>c>>r1>>c1;
    r--; c--; r1--; c1--;

    q.push({r, c});
    dist[r][c] = 0;
    visited[r][c] = true;

    int x, y;

    while(!q.empty()){
        ii curr = q.front();
        q.pop();

        rep(i, 0, 4){
            x = curr.ff + row_num[i];
            y =  curr.ss + col_num[i];

            ii nxt = check1(x, y, n, Move[i]);
            // cout<<nxt.ff<<" "<<nxt.ss<<" "<<curr.ff <<" "<<curr.ss<<" "<<Move[i]<<endl;
            if(nxt.ff != -1 && !visited[nxt.ff][nxt.ss]){
                visited[nxt.ff][nxt.ss] = true;
                dist[nxt.ff][nxt.ss] = dist[curr.ff][curr.ss] + 1;
                q.push(nxt);
            }
        }
    }

    cout<<dist[r1][c1]<<endl;
}