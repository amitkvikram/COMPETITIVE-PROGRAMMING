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
    vector<int> adj;
    bool vis = false;
    // ll dist = inf;
};

int main(){
    string s, t;
    cin>>s>>t;

    vector<node> g(26);

    vector<vector<ll>> adj(26, vector<ll>(26, inf));
    
    // rep(i, 0, 26){
        rep(j, 0, 26){
            adj[j][j] = 0;
        }
    // }

    int m;
    cin>>m;
    char a, b;
    ll w;
    while(m--){
        cin>>a>>b>>w;
        // cout<<a<<b<<endl;
        // cout<<adj[int(a - 'a')][int(b - 'a')]<<endl;
        adj[int(a - 'a')][int(b - 'a')] = min(adj[int(a - 'a')][int(b - 'a')], w);
        // cout<<adj[int(a - 'a')][int(b - 'a')]<<endl;
    }

    rep(k, 0, 26){
        rep(i, 0, 26){
            rep(j, 0, 26){
                adj[i][j] = min(adj[i][k] + adj[k][j], adj[i][j]);
            }
        }
    }

    // rep(i, 0, 26){
    //     rep(j, 0, 26){
    //         if(adj[i][j] == inf)
    //             cout<<-1<<' ';
    //         else
    //         cout<<adj[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }

    bool res = false;
    ll cnt = 0;
    if(s.length() == t.length()){
        res = true;
        for(int i = 0; i < s.length(); i ++){
            int x = s[i] - 'a', y = t[i] - 'a';
            ll curr = inf ;
            rep(j, 0, 26){
                char ch = 'a' + j;
                if(adj[x][j] + adj[y][j] < curr){
                    curr = adj[x][j] + adj[y][j];
                    s[i] = t[i] = ch;
                }
            }

            if(curr == inf){
                res = false;
                break;
            }
            cnt+=curr;
        }
    }

    if(!res){
        cout<<-1<<endl;
    }
    else{
        cout<<cnt<<endl;
        cout<<s<<endl;
    }
}