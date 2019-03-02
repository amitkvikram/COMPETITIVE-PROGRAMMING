#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

#define ff first
#define ss second

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int> > Adj(n, vector<int> (n, 0));

    int a, b;
    while(m--){
        cin>>a>>b;
        a--; b--;
        Adj[a][b] = 1;
        Adj[b][a] = 1;
    }

    queue<ii> q;
    q.push({0, 0});
    int d1 = -1, d2 = -1;

    vector<bool> vis(n, false);
    vis[0] = true;

    while(!q.empty()){
        ii pr = q.front();
        q.pop();

        if(pr.ff == n - 1){
            d1 = pr.ss;
        }

        for(int i = 0; i<n; i++){
            if(Adj[pr.ff][i] == 1 && !vis[i]){
                q.push({i, pr.ss + 1});
                vis[i] = true;
            }
        }
    }

    fill(vis.begin(), vis.end(), false);
    queue<ii>().swap(q);
    q.push({0, 0});
    vis[0] = true;
    while(!q.empty()){
        ii pr = q.front();
        q.pop();

        if(pr.ff == n - 1){
            d2 = pr.ss;
        }

        for(int i = 0; i<n;  i++){
            if(Adj[pr.ff][i] == 0 && !vis[i]){
                q.push({i, pr.ss + 1});
                vis[i] = true;
            }
        }
    }

    if(d1 == -1 || d2 == -1){
        cout<<-1<<endl;
    }
    else{
        cout<<max(d1, d2);
    }
}
