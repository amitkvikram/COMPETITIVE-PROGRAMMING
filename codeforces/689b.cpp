#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

#define ff first
#define ss second

int main(){
    int n;
    cin>>n;
    vi A(n);
    vi dist(n, 0);
    vi vis(n, false);

    for(int i = 0; i<n; i++){
        cin>>A[i];
        // dist[i] = i;
    }

    queue<ii> q;
    q.push({0, 0});
    vis[0] = true;

    while(!q.empty()){
        ii pr = q.front();
        q.pop();

        if(pr.ff > 0 && !vis[pr.ff - 1]){
            dist[pr.ff - 1] = pr.ss + 1;
            vis[pr.ff - 1] = true;
            q.push({pr.ff - 1, pr.ss + 1});
        } 
        if(pr.ff < n - 1 && !vis[pr.ff + 1]){
            dist[pr.ff + 1] = pr.ss + 1;
            vis[pr.ff + 1] = true;
            q.push({pr.ff + 1, pr.ss + 1});
        }
        if(A[pr.ff] - 1 != pr.ff && !vis[A[pr.ff] - 1]){
            dist[A[pr.ff] - 1] = pr.ss + 1;
            vis[A[pr.ff] - 1] = true;
            q.push({A[pr.ff] - 1, pr.ss + 1});
        }
    }

    for(int i = 0; i<n; i++){
        cout<<dist[i]<<' ';
    }
    cout<<endl;
}