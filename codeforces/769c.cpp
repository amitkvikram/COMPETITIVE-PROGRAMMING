#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vii;
#define rep(i, a, b) for(int i = a; i < b; i++)

int row_num[] = {1, 0, 0, -1};
int col_num[] = {0, -1, 1, 0};
char Move[] = {'D', 'L', 'R', 'U'};

#define ff first
#define ss second
#define pb push_back

const ll inf = 1e15 + 7;

class node{
    public:
    vector<int> adj;
    bool vis = false;
    // ll dist = inf;
};

string path;
int n,m, k;
ii source;

bool check(int i, int j){
    return i >=0 && j >=0 && i < n && j < m;
}

bool dfs(ii s, int l, vector<vector<char>> & v, vii &dist){

    if(l == k && s == source){
        return true;
    }

    else if(l > k){
        return false;
    }

    rep(i, 0, 4){
        int x = s.ff + row_num[i];
        int y = s.ss + col_num[i];
        if(check(x, y) && v[x][y] != '*' && dist[x][y] < k - l){
            if(dfs(make_pair(x, y), l + 1, v, dist)){
                path.push_back(Move[i]);
                return true;
            }
        }
    }

    return false;
}


int main(){
    cin>>n>>m>>k;
    vector<vector<char>> v(n, vector<char>(m));
    rep(i, 0, n){
        rep(j, 0, m){
            cin>>v[i][j];
            if(v[i][j] == 'X'){
                source = {i, j};
                v[i][j] = '.';
            }
        }
    }

    if(k%2 != 0){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }

    vector<vector<ll>> dist(n, vector<ll>(m, inf));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<ii> q;

    q.push(source);
    vis[source.ff][source.ss] = true;
    dist[source.ff][source.ss] = 0;

    while(!q.empty()){
        ii curr = q.front();
        q.pop();

        rep(i, 0, 4){
            int x = curr.ff + row_num[i];
            int y = curr.ss + col_num[i];

            if(check(x, y) && v[x][y] != '*' && vis[x][y] == false){
                vis[x][y] = true;
                dist[x][y] = dist[curr.ff][curr.ss] + 1;
                q.push({x, y});
            }
        }
    }

    if(dfs(source, 0, v, dist)){
        reverse(path.begin(), path.end());
        cout<<path<<endl;
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }
}