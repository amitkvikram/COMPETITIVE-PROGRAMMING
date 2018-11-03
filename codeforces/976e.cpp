#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
#define ff first
#define ss second

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    a = max(1, 2 << (a-1));

    // cout << a << endl;

    vector<ii> v(n);

    ll max_ind = 0, max_value = 0;     
    for (ll i = 0; i < n; i++){
        cin >> v[i].ff >> v[i].ss;
        // if (a * v[i].ff - v[i].ss > max_value)
        // {
        //     max_value = a * v[i].ff - v[i].ss;
        //     max_ind = i;
        // }
    }

    sort(v.begin(), v.end(), [](ii a, ii b) {
        return a.ff - a.ss > b.ff - b.ss;
    });

    for (ll i = 0; i < min(b, n); i++)
    {
        if (v[i].ff > v[i].ss)
            v[i].ss = v[i].ff;
    }
    ll init = 0;
    ll res =  std::accumulate(v.begin(), v.end(), init, [](ll x, ii y) { return x + y.ss; });
    ll nres;
    for (int i = 0; i < n; i++)
    {
        
    }
}