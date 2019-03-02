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

class node{
    public:
    int parent  = -1;
    vi child;
    bool visited = false;
    vector<ii> adj;
    ll dist = inf;
    int num = 1;

    // node(){}
};

class pqNode{
    public:
        int ind;
        ll dist;

        pqNode(int ind1, ll dist1){
            ind = ind1;
            dist = dist1;
        }
};

int n, m, k;

class myCompare{
    public:
        bool operator()(const pqNode &p1, const pqNode &p2){
            return p1.dist > p2.dist;
        }
};

vector<int> levelOrder;

void levelOrderTraversal(vector<node> &g){
    vector<bool> visited(n, false);
    visited[0] = true;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        // cout<<curr<<endl;

        levelOrder.pb(curr);

        for(int i = 0; i < g[curr].child.size(); i++){
            int ind = g[curr].child[i];
            if(!visited[ind]){
                visited[ind] = true;
                q.push(ind);
            }
        }
    }
}

int main()
{
    cin>>n>>m>>k;
    int x, y, w;
    vector<node> g(n);
    map<ii, int> mp;
    for(int i = 0; i < m; i++){
        cin>>x>>y>>w;
        x--; y--;

        mp.insert(make_pair(make_pair(min(x, y), max(x, y)), i));
        // mp.insert(make_pair(make_pair(y, x), i));
        g[x].adj.pb({y, w});
        g[y].adj.pb({x, w});
    }

    priority_queue<pqNode, vector<pqNode>, myCompare> pq;

    pq.push(pqNode(0, 0));
    while(!pq.empty()){
        // cout<<"here\n";
        pqNode curr = pq.top();
        pq.pop();

        int ind = curr.ind;
        if(g[ind].visited){
            continue;
        }

        // cout<<"popped = "<<curr.ind<<endl;

        g[ind].visited = true;
        if(g[ind].parent !=-1){
            g[g[ind].parent].child.push_back(ind);
        }


        for(ii elem: g[ind].adj){
            if(curr.dist + elem.ss < g[elem.ff].dist){
                g[elem.ff].dist = curr.dist + elem.ss;
                g[elem.ff].parent = curr.ind;
                pq.push(pqNode(elem.ff, g[elem.ff].dist));
            }
        }
    }

    // updateCount(0, g);
    levelOrderTraversal(g);

    // cout<<"level Ordre\n";
    // for(int i = 0; i < levelOrder.size(); i++){
    //     cout<<levelOrder[i]<<" ";
    // }
    // cout<<endl<<"-------\n";

    k = min(k, n - 1);
    while(levelOrder.size() > k + 1){
        levelOrder.pop_back();
    }

    cout<<k<<endl;
    // cout<<levelOrder.size()<<endl;
    for(int i = levelOrder.size() - 1; i > 0; i--){
        ii edge = {min(levelOrder[i], g[levelOrder[i]].parent), max(levelOrder[i], g[levelOrder[i]].parent)};
        // cout<<"edge = "<<edge.ff<<' '<<edge.ss<<endl;
        int ind = mp.find(edge)->second;
        cout<<ind + 1<<" ";
    }

    cout<<endl;
}