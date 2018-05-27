#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

class vertex{
    public:
      bool visited = false;
      vi adj;
      int in_degree = 0;
};

void dfs(vector<vertex> &g, ll s, auto &v){
    g[s].visited = true;
    cout << v[s] << ' ';
    for (ll i:g[s].adj){
        if(g[i].visited == false){
            dfs(g, i, v);
        }
    }
}

int main()
{
    ll n, tmp;
    cin >> n;
    vi v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    ll ind;
    vector<vertex> g(n);
    for (ll i = 0; i < n; i++)
    {
        ind = lower_bound(v.begin(), v.end(), v[i] * 2) - v.begin();
        if (ind != n && v[ind] == v[i] * 2)
        {
            g[i].adj.push_back(ind);
            g[ind].in_degree++;
        }

        if(v[i] % 3 != 0)
            continue;
        ind = lower_bound(v.begin(), v.end(), v[i] / 3) - v.begin();
        if(ind != n  && v[ind] == v[i]/3)
            g[i].adj.push_back(ind);
            g[ind].in_degree++;
    }

    for (ll i = 0; i < n;i++){
        if(g[i].in_degree == 0){
            dfs(g, i, v);
        }
    }
}
