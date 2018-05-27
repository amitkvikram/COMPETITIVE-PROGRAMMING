  #include<bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    #define ff first
    #define ss second
    typedef pair< int, int > ii;
    #define rep(i, a, b) for(ll i =a; i<b; i++)
    #define pb push_back
    typedef std::vector<ll> vi;
    const ll mod = 1000000007;               //1e9+7
    const ll inf = INT_MAX;

    ll rowNum[] = {-1, 0, 0, 1};
    ll colNum[] = {0, -1, 1, 0};
    ll row_num[] = {-1, 0, 0, 1,-1, 1, 1, -1};
    ll col_num[] = {0, -1, 1, 0, -1, -1, 1, 1};
    char move[] = {'U', 'L', 'R', 'D'};

class graphNode{
    public:
      list<ii> adjlist;
      bool vis = false;
      ll dist = inf;
      vector<int> time;
};

int
main()
{
    int n, m;
    cin >> n >> m;
    int a, b, w;
    vector<graphNode> v(n);

    //Create Undirected Graph
    rep(i, 0, m){
        cin >> a >> b >> w;
        a--; b--;
        
        v[a].adjlist.pb({b, w});
        v[b].adjlist.pb({a, w});
    }

    v[0].dist = 0;
    int k;
    //Take input of time information of passenger landing 
    rep(i, 0, n)
    {
        cin >> k;
        while(k--){
            cin >> a;
            v[i].time.pb(a);
        }
    }

    //Dijkstra
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, 0});
    int ind, time;
    while (!pq.empty())
    {
        ind = pq.top().ss;
        time = pq.top().ff;
        pq.pop();
        if(v[ind].vis == true) continue;
        v[ind].vis = true;
        int tmp = lower_bound(v[ind].time.begin(), v[ind].time.end(), time) - v[ind].time.begin();
        if(tmp!=v[ind].time.size() && v[ind].time[tmp]==time){
            int i = 0;
            for(i = tmp; i< v[ind].time.size()-1; i++){
                if(v[ind].time[i+1]!=v[ind].time[i] + 1) break;
            }
            time = v[ind].time[i] + 1;
        }
        
        for(auto it: v[ind].adjlist){
            if(v[it.ff].vis == false && time + it.ss < v[it.ff].dist){
                v[it.ff].dist = time+ it.ss;
                pq.push({v[it.ff].dist, it.ff});
            }
        }
    }

    if(v[n-1].dist == inf){
        cout<<"-1\n";
    }
    else{
        cout<<v[n - 1].dist<<endl;
    }
    
}