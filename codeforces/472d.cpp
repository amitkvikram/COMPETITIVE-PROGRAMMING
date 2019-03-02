#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll, ll> ii;
const ll inf = 1e18;

#define ff first
#define ss second
#define rep(i, a, b) for(int i = a; i < b; i++)

class node{
    public:
    ll sz = 1;
    ll id = -1;
};

void setId(vector<node> &g){
    for(int i = 0; i < g.size(); i++){
        g[i].id = i;
    }
}

int root(int i, vector<node>&g){
    while(i != g[i].id){
        g[i].id = g[g[i].id].id;
        i = g[i].id;
    }

    return i;
}

bool connected(int i, int j, vector<node> &g){
    return root(i, g) == root(j, g);
}

void union1(int i, int j, vector<node> &g){
    int ind1 = root(i, g);
    int ind2 = root(j, g);

    // if(ind1 == ind2) return;

    if(g[ind1].sz < g[ind2].sz){
        g[ind1].id = g[ind2].id;
        g[ind2].sz += g[ind1].sz;
    }
    else{
        g[ind2].id = g[ind1].id;
        g[ind1].sz += g[ind2].sz;
    }
}

class edge{
    public:
        int s;
        int d;
        int w;

    edge(int s1, int d1, int w1){
        s = s1;
        d = d1;
        w = w1;
    }
    edge(){}
};

bool myCompare(const edge &p1, const edge &p2){
    return p1.w < p2.w;
}

class gNode{
    public:
    vector<ii> adjList;
    bool vis = false;
    ll dist = inf;
};

ll d[2002][2002];

int main(){
    int n;
    cin>>n;
    // vii d(n, vi(n, inf));
    rep(i, 0, n){
        rep(j, 0, n){
            // cin>>d[i][j];
            scanf("%lld", &d[i][j]);
        }
    } 

    vector<node> g(n);    //for dsu
    vector<edge> edges;

    bool res = true;

    //Checking if matrix is symmetry or not
    // if(res){
    rep(i, 0, n){
        if(d[i][i] != 0) res = false;
        rep(j, i + 1, n){
            if(d[i][j] != d[j][i] || d[i][j] == 0){
                res = false;
            }
        }
    }
    // }

    //Constructing mst of tree(which will be original tree itself) using shortest distance matrix
    if(res){
        rep(i, 0, n){
            rep(j, i + 1, n){
                edges.push_back(edge(i, j, d[i][j]));
            }
        }

        sort(edges.begin(), edges.end(), myCompare);

        vector<gNode> graph(n);
        setId(g);
        int cnt = 0;
        for(edge e:edges){
            if(!connected(e.s, e.d, g)){
                union1(e.s, e.d, g);
                graph[e.s].adjList.push_back({e.d, e.w});
                graph[e.d].adjList.push_back({e.s, e.w});
            }
        }

        // cout<<"tree constructed\n";

        //Tree constructed;
        rep(i, 0, n){
            rep(j, 0, n){
                graph[j].dist = inf;
                graph[j].vis = false;
            }

            graph[i].dist = 0;
            graph[i].vis = true;

            queue<int> q;
            q.push(i);

            while(!q.empty()){
                int curr = q.front();
                q.pop();

                for(ii elem: graph[curr].adjList){
                    if(graph[elem.ff].vis == false){
                        graph[elem.ff].vis = true;
                        graph[elem.ff].dist = graph[curr].dist + elem.ss;
                        q.push(elem.ff);
                    }
                }
            } 

            rep(j, 0, n){
                if(d[i][j] != graph[j].dist){
                    res = false;
                }
            }
        }
    }

    if(!res) cout<<"NO\n";
    else cout<<"YES\n";
}
