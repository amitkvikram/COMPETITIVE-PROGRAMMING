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

bool check(int i, int j, int n, int m){
    return i >= 0 && j >=0 && i < n && j < m;
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<char>> v(n, vector<char>(m));
    char ch;
    ii source, exit1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>ch;
            if(ch == 'T'){
                v[i][j] = '*';
            }
            else if(ch == 'S'){
                source = {i, j};
                v[i][j] = '0';
            }
            else if(ch == 'E'){
                exit1 = {i, j};
                v[i][j] = '0';
            }
            else{
                v[i][j] = ch;
            }
        }
    }

    int x, y, fight = 0;
    vector<vector<int>> dist(n, vector<int>(m, inf));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<ii> q;
    x = exit1.ff; y = exit1.ss;
    dist[x][y] = 0;
    visited[x][y] = false;

    q.push({x, y});
    while(!q.empty()){
        ii curr = q.front();
        q.pop();
        rep(i, 0, 4){
            x = curr.ff + row_num[i];
            y = curr.ss + col_num[i];

            if(!check(x, y, n, m ) || v[x][y] == '*' || visited[x][y]) continue;

            visited[x][y] = true;
            q.push({x, y});
            dist[x][y] = dist[curr.ff][curr.ss] + 1;
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j< m; j++){
            if(dist[i][j] <=    dist[source.ff][source.ss]){
                fight+=int(v[i][j] - '0');
            }
        }
    }

    cout<<fight<<endl;
}