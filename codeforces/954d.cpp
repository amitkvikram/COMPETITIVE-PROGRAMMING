#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int, int> ii;

#define ff first
#define ss second

int main(){
    int n, m, s, t;
    cin>>n>>m>>s>>t;
    s--; t--;

    vii Adj(n, vector<int> (n, 0));
    int a, b;
    while(m--){
        cin>>a>>b;
        a--; b--;

        Adj[a][b] = 1;
        Adj[b][a] = 1;
    }

    vi level_s(n, 0), level_t(n, 0);

    queue<int> q;
    q.push(s);
    vector<bool> vis(n, false);
    vis[s] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i = 0; i < n; i++){
            if(vis[i] == false && Adj[node][i] == 1){
                vis[i] = true;
                q.push(i);
                level_s[i] = level_s[node] + 1;
            }
        }
    }

    fill(vis.begin(), vis.end(), false);
    vis[t] = true;
    q.push(t);
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i = 0; i<n; i++){
            if(vis[i] == false && Adj[node][i] == 1){
                vis[i] = true;
                q.push(i);
                level_t[i] = level_t[node] + 1;
            }
        }
    }

    int res = 0;

    for(int i = 0; i<n; i++){
        for(int j = i + 1; j< n; j++){
            if(Adj[i][j] == 0){
                if(level_s[i] + level_t[j] + 1 >= level_s[t] &&
                    level_t[i] + level_s[j] + 1 >= level_s[t]){
                        res++;
                    }
            }
        }
    }

    cout<<res<<endl;
}