#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef long long ll;

#define ff first
#define ss second
#define rep(i, a, b) for(int i = a; i<b; i++)
const ll inf = LLONG_MAX;

int row_num[] = {0, 0, -1, 1};
int col_num[] = {-1, 1, 0, 0};
char Move[] = {'A', 'B', 'C', 'D'};

bool check(int i, int j, int n, int m){
    return i>=0 && j>=0 && i<n && j<m;
}

class node{
    public: 
    vector<ii> adj;
    bool visited;
    ll parentDist = inf;  //distance between node and its parent(shortest path parent)
    ll dist;
};

int main(){
    int n;
    cin>>n;

    int q;
    rep(i, 0, n){
        cin>>q;
    }

    int m;
    cin>>m;
    ll a, b, c;
    vector<node> g(n);

    while(m--){
        cin>>a>>b>>c;
        a--; b--;
        g[b].parentDist = min(c, g[b].parentDist);
    }

    int cnt = 0;
    ll maximum = -1, sum1 = 0;

    for(int i = 0; i<n; i++){
        if(g[i].parentDist == inf){
            cnt++;
        }
        else {
            if(g[i].parentDist > maximum){
                maximum = g[i].parentDist;
            }
                sum1+=g[i].parentDist;
        }
    }

    if(cnt > 1){
        cout<<-1<<endl;
    }
    else{
        if(cnt == 1){
            // cout<<"here\n";
            cout<<sum1<<endl;
        }
        else{
            cout<<sum1 - maximum<<endl;
        }
    }
}