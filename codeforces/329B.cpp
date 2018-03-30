#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ff first
#define ss second
typedef pair< ll, ll > ii;
#define rep(i, a, b) for(ll i =a; i<b; i++)
#define pb push_back
typedef std::vector<ll> vi;
const ll mod = 1000000007;               //1e9+7
const ll inf = LONG_MAX;

ll rowNum[] = {-1, 0, 0, 1};
ll colNum[] = {0, -1, 1, 0};

class graphNode{
    public:
      list<ii> adjList;
      bool visited = false;
      bool explored = false;

      ll dist = inf;
      ll train = inf;
};

void dijkstra(auto &v, ll &res){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, 0});
    v[0].dist = 0;
    while(!pq.empty()){
        ii tmp = pq.top();
        pq.pop();
        ll ind = tmp.ss;
        ll d = tmp.ff;
        if(v[ind].visited == true)
            continue;
        if(v[ind].train != inf){
            if(d <= v[ind].train ){
                res++;
            }
            else{
                v[ind].dist = d = v[ind].train;
            }
        }
        v[ind].visited = true;
        for (auto i : v[ind].adjList)
        {
            if(v[i.ff].visited == false && v[i.ff].dist > d+i.ss){
                v[i.ff].dist = d + i.ss;
                pq.push({v[i.ff].dist, i.ff});
            }
        }
    }
}


int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll a, b, wt;
    vector<graphNode> v(n);
    rep(i, 0, m){
        cin >> a >> b >> wt;
        a--;
        b--;
        v[a].adjList.push_back({b, wt});
        v[b].adjList.pb({a, wt});

    }
     ll res = 0;

    rep(i, 0, k){
        cin >> a >> b;
        a--;
        if(b<v[a].train)
            v[a].train = b;
        else
            res++;
    }
    dijkstra(v, res);
    cout << res << endl;
    return 0;
}