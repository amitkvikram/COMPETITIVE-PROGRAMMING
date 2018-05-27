  #include<bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    #define ff first
    #define ss second
    typedef pair< int, int > ii;
    #define rep(i, a, b) for(ll i =a; i<b; i++)
    #define pb push_back
    typedef std::vector<int> vi;
    const ll mod = 1000000007;               //1e9+7
    const ll inf = LLONG_MAX;

    ll rowNum[] = {-1, 0, 0, 1};
    ll colNum[] = {0, -1, 1, 0};
    ll row_num[] = {-1, 0, 0, 1,-1, 1, 1, -1};
    ll col_num[] = {0, -1, 1, 0, -1, -1, 1, 1};
    char move[] = {'U', 'L', 'R', 'D'};

void relax(int k, int n, auto &v, ll &total){
    // cout << "k=" << k << endl;
    for (int i = n - 1; i >= 0; i--)
    {
        for(int j = n-1; j>=0; j--){
            if(v[i][k] + v[k][j] < v[i][j]){
                total -= v[i][j];
                v[i][j] = v[i][k] + v[k][j];
                total += v[i][j];
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<ll>> v(n, vector<ll>(n));
    ll total = 0;

    rep(i, 0, n){
        rep(j, 0, n){
            cin >> v[i][j];
            total += v[i][j];
        }
    }
    int k;
    cin >> k;
    int a, b, w;
    while(k--){
        cin >> a >> b >> w;
        a--;
        b--;
        if ((v[a][b] >w)){
            total -= 2*v[a][b];
            v[a][b] = w;
            v[b][a] = w;
            total += 2*w;
            int tmp = min(a, b);
            a = max(a, b);
            b = tmp;
            relax(a, n, v, total);
            relax(b, n, v, total);
        }
        // cout << endl;
        // rep(i, 0, n)
        // {
        //     rep(j, 0, n){
        //         cout << v[i][j]<<' ';
        //     }
        //     cout << endl;
        // }
        cout << total / 2 << ' ';
    }
    // rep(i, 0, n){
    //     rep(j, 0, n){
    //         cout << v[i][j]<<' ';
    //     }
    //     cout << endl;
    // }
    // cout << total/2 << endl;
}
