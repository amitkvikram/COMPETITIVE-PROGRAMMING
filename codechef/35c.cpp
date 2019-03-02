#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

#define ff first
#define ss second
#define rep(i, a, b) for(int i = a; i<b; i++)

int row_num[] = {0, 0, -1, 1};
int col_num[] = {-1, 1, 0, 0};
char Move[] = {'A', 'B', 'C', 'D'};

bool check(int i, int j, int n, int m){
    return i>=0 && j>=0 && i<n && j<m;
}

int main(){
    int n, m;
    cin>>n>>m; 

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); 

    bool visited[2000][2000];

    rep(i, 0, n){
        rep(j, 0, m){
            visited[i][j] = false;
        }
    }
    int k;
    cin>>k;
    queue<ii> q;

    ii last;
    int x, y;

    while(k--){
        cin>>x>>y;
        x--; y--;
        q.push(make_pair(x, y));
        cout<<x<<" "<<y<<endl;
        visited[x][y] = true;
    }

    while(!q.empty()){
        ii curr = q.front();

        q.pop();
        last = curr;
        rep(i, 0, 4){
            x = curr.ff + row_num[i];
            y = curr.ss + col_num[i];

            if(check(x, y, n, m) && visited[x][y] == false){
                visited[x][y] = true;
                q.push(make_pair(x, y));
            }
        }
    }

    cout<<last.ff + 1<<" "<<last.ss + 1<<endl;

    return 0;
}