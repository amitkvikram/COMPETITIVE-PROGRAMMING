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
vi prsum(vi v){vi temp(v.size()); rep(i,0,v.size()){if(i>0) temp[i]=temp[i-1]+v[i];else temp[i] = v[i];}return temp;}

const ll mod = 1000000007;  

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

class vertex{
    public:
    vector<int> adj;
    bool visited = false;
    int parent = -1;

};

queue<int> leaf;

void dfs(vector<vertex> &v, int ind){
    v[ind].visited = true;
    int cnt = 0;
    for(auto elem:v[ind].adj){
        if(v[elem].visited == false){
            cnt++;
            v[elem].parent = ind;
            dfs(v, elem);
        }
    }
    if(cnt == 0) leaf.push(ind);
}

int main(){
    int n;
    cin>>n;

    vector<vertex> v(n);
    int a, b;
    rep(i, 0, n - 1){
        cin>>a>>b;
        a--; b--;
        v[a].adj.pb(b);
        v[b].adj.pb(a);
    }
    
    dfs(v, 0);

    bool status = true;
    int cnt = 0;
    rep(i, 0, n) v[i].visited = false;
    while(1){
        int n = leaf.size();
        // cout<<leaf.size()<<endl;
        if(leaf.size() == 0) break;
        for(int i = 0; i<n; i++){
            int ind = leaf.front();
            int parent = v[ind].parent;
            leaf.pop();
            if(v[ind].visited == true) continue;
            if(v[parent].visited == true){
                status = false;
                break;
            }

            v[ind].visited = true;
            v[parent].visited = true;
            cnt++;
            if(v[parent].parent!=-1 && v[v[parent].parent].visited == false) leaf.push(v[parent].parent);
        }
    }

    if(status == false) cout<<"-1";
    else cout<<n - 1 - cnt;
    cout<<endl;
    return 0;
}