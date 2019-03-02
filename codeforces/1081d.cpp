//CF_1076D

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;

#define ff first
#define ss second
#define pb push_back

const ll inf = 1e15 + 7;

class edge{
    public:
    ll s;
    ll d;
    ll w;
    edge(ll s1, ll d1, ll w1){
        s = s1;
        d = d1;
        w = w1;
    }

    edge(){}
};

class myCompare{
    public:
    bool operator()(const edge &p1, const edge &p2){
        return p1.w < p2.w;
    }
};

bool comp(const edge &p1, const edge &p2){
    return p1.w < p2.w;
}

class node{
    public:
    ll sz = 1;
    ll parent = -1;
};

void setParent(vector<node> &g){
    for(int i = 0; i < g.size(); i++){
        g[i].parent = i;
    }
}

int root(int ind, vector<node> &g){
    while(ind != g[ind].parent){
        g[ind].parent = g[g[ind].parent].parent;
        ind = g[ind].parent;
    }

    return ind;
}

bool connected(int ind1, int ind2, vector<node> &g){
    return root(ind1, g) == root(ind2, g);
}

void union1(int ind1, int ind2, vector<node> &g){
    int i = root(ind1, g);
    int j = root(ind2, g);
    if(i == j) return;
    if(g[i].sz < g[j].sz){
        g[i].parent = j;
        g[j].sz += g[i].sz;
    }
    else{
        g[j].parent = i;
        g[i].sz += g[j].sz;
    }
}

int main(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<bool> special(n, false);
    int x_i;
    for(int i = 0 ; i < k; i++){
        cin>>x_i;
        x_i--;
        special[x_i] = true;
    }

    ll u, v, w;

    vector<edge> edges;
    ll maxWt = -1;

    while(m--){
        cin>>u>>v>>w;
        u--; v--;
        edges.push_back(edge(u, v, w));
    }

    vector<node> g(n);
    sort(edges.begin(), edges.end(), comp);
    setParent(g);
    vector<edge> mst;
    int cnt = 0, i =  0;
    edge e;
    for(int i = 0; i < edges.size(); i++){
        if(cnt >= n - 1){
            break;
        }

        e = edges[i];
        // cout<<"out: "<<e.s<<" "<<e.d<<endl;
        if(!connected(e.s, e.d, g)){
            cnt++;
            union1(e.s, e.d, g);
            mst.push_back(e);
            // cout<<e.s<<" "<<e.d<<endl;
            if(special[e.s] || special[e.d]){
                // maxWt = max(maxWt, e.w);
                special[e.s] = true;
                special[e.d] = true;
            }
        }
    }

    for(int i = 0; i < mst.size(); i ++ ){
        e = mst[i];
        if(special[e.s] || special[e.d]){
            maxWt = max(maxWt, e.w);
        }
    }

    for(int i = 0; i < k; i ++){
        cout<<maxWt<<" ";
    }

    cout<<endl;
}