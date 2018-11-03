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
    const ll inf = LLONG_MAX;

    ll rowNum[] = {-1, 0, 0, 1};
    ll colNum[] = {0, -1, 1, 0};
    ll row_num[] = {-1, 0, 0, 1,-1, 1, 1, -1};
    ll col_num[] = {0, -1, 1, 0, -1, -1, 1, 1};
    char move[] = {'U', 'L', 'R', 'D'};

class graphNode{
    public:
      list<pair<ll, ii>> adjlist;
      bool vis = false;
      ll edge_index;
      ll dist = inf;
};

int
main()
{
    ll n, m;
    cin >> n >> m;
    vector<graphNode> v(n);
    vector<ll> Edge(m);
    ll a, b, w;
    rep(i, 1, m+1){
        cin >>a>>b >> w;
        a--;
        b--;
        Edge[i - 1] = w;
        v[a].adjlist.pb({i, {b, w}});
        v[b].adjlist.pb({i, {a, w}});
    }

    vector<ll> tree;
    priority_queue<ii, vector<ii>, greater<ii>> pq;

    ll s, total_wt = 0; //source vertex;
    cin >> s;
    v[s-1].dist = 0;
    pq.push({0, s-1});
    while(!pq.empty()){
        ii tmp = pq.top();
        pq.pop();
        long long dist = tmp.ff;
        ll ind = tmp.ss;
        if(v[ind].vis == true)
            continue;
        v[ind].vis = true;
        if (ind != s-1)
        {
            tree.push_back(v[ind].edge_index);
        }
        for (auto it : v[ind].adjlist)
        {
            if(v[it.ss.ff].vis == false){
                if(dist + it.ss.ss <= v[it.ss.ff].dist){
                    v[it.ss.ff].dist = dist + it.ss.ss;
                    pq.push({v[it.ss.ff].dist, it.ss.ff});
                    v[it.ss.ff].edge_index = it.ff;
                }
            }
        }
    }
    // return 0;
    for (auto i : tree)
    {
        total_wt += Edge[i-1];
    }

    cout << total_wt << endl;
    for(auto i:tree){
        cout << i << ' ';
    }
    cout << endl;
}