#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vector<int>> vii;

#define ff first
#define ss second
const long INF = 1e8;

void bfs(int k, vii &dist, vii &Adj, vi &A, vii &A_rev, int n){
    vector<bool> vis(n, false);
    queue<ii> q;
    for(int i = 0; i<A_rev[k].size(); i++){
        int node = A_rev[k][i];
        q.push({node, 0});
        vis[node] = true;
    }

    while(!q.empty()){
        ii pr = q.front();
        q.pop();
        // int x = A[pr.ff];
        int x = pr.ff;

        // if(pr.ss < dist[s][x]){
        dist[x][k] = pr.ss;
        // }

        for(int i = 0; i < Adj[x].size(); i++){
            int nxt = Adj[x][i];
            if(!vis[nxt]){
                vis[nxt] = true;
                q.push({nxt, pr.ss + 1});
            }
        }
    }
}

int getSum(vi &v, int s){
    sort(v.begin(), v.end());
    int sum = 0;
    for(int i = 0; i<s; i++){
        sum+=v[i];
    }

    return sum;
}

int main(){
    int n, m, k, s;
    cin>>n>>m>>k>>s;

    vector<vector<int>> dist(n, vector<int> (k, INF));
    vector<vector<int>> Adj(n);
    vector<int> A(n); 

    vector<vector<int>> A_rev(k);

    for(int i = 0; i<n; i++){
        cin>>A[i];
        A[i]--;
        A_rev[A[i]].push_back(i);
    }

    int a, b;
    while(m--){
        cin>>a>>b;
        a--; b--;

        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }

    for(int i = 0; i<k; i++){
        bfs(i, dist, Adj, A, A_rev, n);
    }

    for(int i = 0; i<n; i++){
        cout<<getSum(dist[i], s)<<" ";
    }

    cout<<endl;

    return 0;
}