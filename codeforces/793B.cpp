  #include<bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    // #define ff first
    // #define ss second
    #define rep(i, a, b) for(int i =a; i<b; i++)
    #define pb push_back
    typedef std::vector<ll> vi;
    const ll mod = 1000000007;               //1e9+7
    const ll inf = LLONG_MAX;

    ll row_num[] = {-1, 0, 0, 1};
    ll col_num[] = {0, -1, 1, 0};
    char Move[] = {'U', 'L', 'R', 'D'};

bool check(int i, int j, int n, int m)
{
    return i < n && j < m && i >= 0 && j >= 0;
}

class pt{
    public:
      int x;
      int y;
};

// typedef pair< int , pt> ii;
class ii{
    public:
      int ff;
      pt ss;
};

class myCompare
{
  public:
    int operator()(const ii & p1, const ii &p2){
        return p1.ff > p2.ff;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> v(n, vector<char>(m));
    pt s, T;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> count(n, vector<int>(m, 2000));

    rep(i, 0, n){
        rep(j, 0, m){
            cin >> v[i][j];
            if(v[i][j] == 'S')
                s = {i, j};
            else if(v[i][j] == 'T')
                T = {i, j};
        }
    }
    // cout << T.x << ' ' << T.y << endl;
    priority_queue<ii, vector<ii>, myCompare> pq;
    pq.push({0,s});
    visited[s.x][s.y] = true;
     count[s.x][s.y] = 0;
    rep(i, 0, 4){
        int x = s.x + row_num[i];
        int y = s.y + col_num[i];
                // cout << "x=" << x << ' ' << "y = " << y << endl;
         if(!(check(x, y, n, m)) || v[x][y] == '*')
                continue;
        v[x][y] = Move[i];
        pq.push({0, {x, y}});
        count[x][y] = 0;
    }

    int it = 0;
    while (!pq.empty())
    {
        pt t = pq.top().ss;
        int val = pq.top().ff;
        pq.pop();
        // it++;
        // if(it>5)
        //     break;
        // cout << t.x << ' ' << t.y << endl;
        int x = t.x, y = t.y;
        if(visited[x][y] == true)
            continue;
        visited[x][y] = true;
        // cout << "Node = "<<t.x << ' ' << t.y << ' '<<val<<endl;

        rep(i, 0, 4){
            x = t.x + row_num[i];
            y = t.y + col_num[i];
            if(!(check(x, y, n, m)) || v[x][y] == '*')
                continue;
            if (v[t.x][t.y] == Move[i])
            {
                if(val<count[x][y]){
                    // cout << x << ' ' <<y <<' '<<i<<' '<<v[t.x][t.y]<<endl;
                    pq.push({val, {x, y}});
                    count[x][y] = val;
                    v[x][y] = Move[i];
                }
            }
            else{
                if(val+1<count[x][y]){
                    // cout << x << ' ' <<y <<' '<<i<<' '<<v[t.x][t.y]<<endl;
                    count[x][y] = val + 1;
                    pq.push({val + 1, {x, y}});
                    v[x][y] = Move[i];
                }
            }
        }
    }

    if(count[T.x][T.y] <= 2){
        cout << "YES\n";
    }
    else
        cout << "NO\n";
}