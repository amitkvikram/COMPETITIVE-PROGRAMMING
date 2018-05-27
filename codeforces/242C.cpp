  #include<bits/stdc++.h>
  #include<boost/functional/hash.hpp>
    using namespace std;

    typedef long long ll;
    #define ff first
    #define ss second
    typedef pair< int, int > ii;
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

    int main()
    {
        int sx, sy, tx, ty;
        cin >> sx >> sy >> tx >> ty;
        int n;
        cin >> n;
        int r, c1, c2;
        map<ii, int> mymap;
        while (n--)
        {
            cin >> r >> c1 >> c2;
            rep(col, c1, c2 + 1)
            {
                mymap.insert({{r, col}, -1});
            }
        }

        queue<ii> q;
        q.push({sx, sy});
        mymap.at({sx, sy}) = 0;
        while (!q.empty())
        {
            ii tmp = q.front();
            int val = mymap.find(tmp)->ss;
            q.pop();
            rep(i, 0, 8)
            {
                int  x = tmp.ff + row_num[i];
                int y = tmp.ss + col_num[i];
                auto it = mymap.find({x, y});
                if(it!=mymap.end() && it->ss == -1){
                    it->ss = val+1;
                    q.push({x, y});
                }
            }
        }

        auto it = mymap.find({tx, ty});
        if(it!=mymap.end()){
            cout << it->ss<<endl;
        }
        else
            cout << "-1\n";
    }