    #include<bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    typedef vector<ll> vi;
    typedef pair<ll, ll> ii;
    typedef vector<ii> vii;
    #define ss second
    #define ff first
    #define pb push_back
    #define pf push_front
    #define rep(i, a, b) for(int i = a; i<b; i++)
    #define all(v) v.begin(), v.end()

    ll sum(vi v){ll init = 0; return accumulate(v.begin(), v.end(), init);}
    ll sum(vii v, int check){
        ll init = 0;
        if(check == 1)
        return accumulate(v.begin(), v.end(), init, [](ll a, ii b){
            return a+b.ff;
        });
        else 
        return accumulate(v.begin(), v.end(), init, [](ll a, ii b){
            return a+b.ss;
        });
    }
    vi prsum(vi v){vi temp(v.size()); rep(i,0,v.size()){
        if(i>0) temp[i]=temp[i-1]+v[i];else temp[i] = v[i];}return temp;}

    const ll mod = 1000000007;  

    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    class node{
        public:
        vector<int> adj;
        bool visited = false;
    };

    stack<int> st;

    void fillOrder(vector<node> &v, int s){
        v[s].visited = true;
        for(int i:v[s].adj){
            if(v[i].visited == false){
                fillOrder(v, i);
            }
        }

        st.push(s);
    }

    void dfs(vector<node> &v, int s){
        v[s].visited = true;
        for (int i : v[s].adj)
        {
            if(v[i].visited == false){
                dfs(v, i);
            }
        }
    }

    int main(){
        int n, m, s;
        cin >> n >> m >> s;
        s--;

        vector<node> graph(n);
        int u, v;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            u--;
            v--;
            graph[u].adj.push_back(v);
        }

        int res = 0;

        for (int i = 0; i < n; i++){
            if(!graph[i].visited){
                fillOrder(graph, i);
            }
        }

        for (int i = 0; i < n; i++){
            graph[i].visited = false;
        }

        // dfs(graph, s);

        while(!st.empty()){
            int v1 = st.top();
            st.pop();

            if(graph[v1].visited==false){
                dfs(graph, v1);
            }
        }

        cout << res<< endl;
    }