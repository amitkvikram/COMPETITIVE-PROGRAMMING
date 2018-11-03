#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;

int main(){
    int n, m;
    cin>>n>>m;
    vi v(n);
    vi pv(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
        if(i>0) pv[i] = v[i] + pv[i-1];
        else pv[i] =v[i];
    }

    ll l;
    for(int i = 0; i<m; i++){
        cin>>l;
        int ind = lower_bound(pv.begin(), pv.end(), l) - pv.begin();

        cout<<ind+1<<' ';
        if(ind>0) cout<<l - pv[ind - 1];
        else cout<<l;
        cout<<endl;
    }
}