#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll, ll> ii;
const ll inf = 1e18;

#define rep(i, a, b) for(int i = a; i < b; i++)
#define ff first
#define ss second

int main(){
    int n;
    cin>>n;

    vii adj(n, vi(n, inf));
    rep(i, 0, n){
        rep(j, 0, n){
            cin>>adj[i][j];
        }
    }

    vi x(n);
    rep(i, 0, n){
        cin>>x[i];
        x[i]--;
    }

    reverse(x.begin(), x.end());
    vector<ll> res;

    vii D = adj;
    int k;

    rep(k1, 0, n){
        k = x[k1];
        for(int i:x){
            for(int j:x){
                D[i][j] = min(D[i][k] + D[k][j], D[i][j]);
            }
        }

        ll sum1 = 0;
        for(int i = 0; i < k1 + 1; i++){
            for(int j = 0; j < k1 + 1; j++ ){
                sum1+=D[x[i]][x[j]];
            }
        }

        res.push_back(sum1);
    }

    reverse(res.begin(), res.end());
    for(ll sum1:res){
        cout<<sum1<<' ';
    }

    cout<<endl;
}