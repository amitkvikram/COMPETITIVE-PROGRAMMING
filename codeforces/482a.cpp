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
vi prsum(vi v){
    vi temp(v.size()); rep(i,0,v.size()){if(i>0) temp[i]=temp[i-1]+v[i];else temp[i] = v[i];}return temp;}

const ll mod = 1000000007;  
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

class vertex{
    public:
    vector<ll> adj;
    bool vis = false;
    ll sz = 1;
    ll parent;
};

ll res = 0;
ll n, x, y;


ll compute(ll ind, vector<vertex> &v){
    v[ind].vis = true;
    for(auto elem: v[ind].adj){
        if(v[elem].vis == false){
            v[elem].vis = true;
            v[ind].sz+=compute(elem, v);
            v[elem].parent = ind;
        }
    }
    return v[ind].sz;
}

int main(){
    cin>>n>>x>>y;
    x--; y--;
    ll a, b;
    vector<vertex> v(n);
    for(int i = 0; i<n-1; i++){
        cin>>a>>b;
        a--; b--;
        v[a].adj.pb(b);
        v[b].adj.pb(a);
    }

    compute(x, v);
    ll  z = y;
    while(v[z].parent!=x){
        z = v[z].parent;
    }
    res = (n*(n - 1)) - (v[x].sz - v[z].sz)*v[y].sz;
    cout<<res<<endl;
}