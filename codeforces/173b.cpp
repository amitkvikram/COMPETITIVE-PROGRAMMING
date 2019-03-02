#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;
#define rep(i, a, b) for(int i = a; i < b; i++)

#define ff first
#define ss second
#define pb push_back

const ll inf = 1e15 + 7;

class node{
    public:
    int x; 
    int y;
    int n;
    bool left;
    node(int x1, int y1, int n1){
        x = x1;
        y = y1;
        n = n1;
    }

    node(){}
};

int main(){
    int n, m;
    cin>>n>>m;
    n; m++;
    vector<vector<char>> v(n, vector<char>(m, '.'));

    rep(i, 0, n){
        rep(j, 1, m){
            cin>>v[i][j];
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<bool> row(n, false);
    vector<bool> col(m, false);
    queue<node> q;
    
    for(int i = 0; i < m; i++){
        vis[n - 1][i] = true;
        q.push(node(n-1, i, 0));
    }

    row[n-1] = true;

    node curr;
    int x, y, d;

    int res = -1;

    while(!q.empty()){
        curr = q.front();
        q.pop();

        // cout<<curr.x<<' '<<curr.y<<endl;

        if(curr.x == 0 && curr.y == 0){
            res = curr.n;
            break;
        }

        if(v[curr.x][curr.y] == '#'){
            if(!row[curr.x]){
                row[curr.x] = true;
                for(int i = 0; i < m; i++){
                    if(vis[curr.x][i] == false){
                        vis[curr.x][i] = true;
                        q.push(node(curr.x, i, curr.n + 1));
                    }
                }
            }

            if(!col[curr.y]){
                col[curr.y] = true;
                for(int i = 0; i < n; i ++){
                    if(vis[i][curr.y] == false){
                        vis[i][curr.y] = true;
                        q.push(node(i, curr.y, curr.n + 1));
                    }
                }
            }
        }
    }

    cout<<res<<endl;
}