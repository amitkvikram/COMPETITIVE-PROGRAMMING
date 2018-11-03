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
const int inf = INT_MAX;

int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};
int row_num[] = {-1, 0, 0, 1,-1, 1, 1, -1};
int col_num[] = {0, -1, 1, 0, -1, -1, 1, 1};
char move[] = {'U', 'L', 'R', 'D'};

int main(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--;
    t--;
    vector<vector<int>> v(n, vector<int>(n, 0));
    int a, b;
    rep(i, 0, m){
        cin >> a >> b;
        a--;
        b--;
        v[a][b] = 1;
        v[b][a] = 1;
    }

    queue<int> q;
    vector<bool> vis(n, false);
    q.push(s);
    vis[s] = true;
    vector<int> level_s(n, 0);
    vector<int> level_t(n, 0);

    //BFS for s as root
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        rep(i, 0, n){
            if(vis[i] == false && v[tmp][i] == 1){
                q.push(i);
                level_s[i] = level_s[tmp] + 1;
                vis[i] = true;
            }
        }
    }

    // cout << level_s[t] << endl;
    //BFS for t as root
    fill(vis.begin(), vis.end(), false);
    q.push(t);
    vis[t] = true;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        rep(i, 0, n){
            if(vis[i] == false && v[tmp][i] == 1){
                q.push(i);
                level_t[i] = level_t[tmp] + 1;
                vis[i] = true;
            }
        }
    }

    // cout << level_t[s] << endl;
    //Go through all pair of nodes and check if a road can be added without violation the condition
    int res = 0;
    rep(i, 0, n)
    {
        rep(j, i+1, n){
            if(v[i][j] == 0){
                if(level_s[i] + level_t[j] + 1 >= level_s[t] && level_t[i] + level_s[j] + 1 >= level_s[t]){
                    // cout << i+1 << 'A' << j+1 << endl;
                    res++;
                } 
            }
        }
    }

    cout << res << endl;
    return 0;
}