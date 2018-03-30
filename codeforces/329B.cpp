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

    class graphNode{
        public:
        list<ii> adjList;
        bool visited = false;
        int id = -1;
        int sz = 0;
    };

    int find(auto &v, int ind){
        while(v[ind].id!=ind){
            v[ind].id = v[v[ind].id].id;
            ind = v[ind].id;
        }
        return ind;
    }

    void union1(auto &v, int i, int j){
        int a = find(v, i);
        int b = find(v, j);
        if(a == b)
            return;
        if(v[a].sz < v[b].sz){
            v[b].sz += v[a].sz;
            v[b].id = a;
        }
        else{
            v[a].sz += v[b].sz;
            v[a].id = b;
        }
    }

    bool connected(auto &v, int i, int j){
        return find(i) == find(j);
    }

    int main()
    {
        int n;
        cin >> n;
        vector<vector<int>> adjmat(n, vector<int>(n));

        vector<graphNode> v(n);
        rep(i, 0, n){
            v[i].id = i;
        }

        rep(i, 0, n){
            rep(j, 0, n){
                cin >> adjmat[i][j];
            }
        }

        bool flag = true;

        rep(i, 0, n){
            rep(j, i, n){
                if(i == j){
                    if(adjmat[i][j] != 0){
                        flag = false;
                        break;
                    }
                }
                else{
                    if(adjmat[i][j] != adjmat[j][i]){
                        flag = false;
                        break;
                    }
                    else{
                        if(connected(v, i, j)){
                            flag = false;
                            break;
                        }
                        union1(v, i, j);
                    }
                }
            }
            if(flag == false)
                break;
        }

        int cnt = 0;
        rep(i, 0, n)
        {
            if(v[i].id == i)
                cnt++;
            if(cnt>1){
                flag = false;
                break;
            }
        }

        

        return 0;
    }