#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
#define ff first
#define ss second

int main(){
    int n, w;
    cin>>n>>w;
    vector<ii> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i].ff;
        v[i].ss = 0;
    }

    int  a, b;
    for(int i = 0; i<w; i++){
        cin>>a>>b;

        if(v[b - 1].ff > v[a - 1].ff){
            v[b - 1].ss--;
        }

        else if(v[a - 1].ff > v[b - 1].ff){
            v[a - 1].ss--;
        }
    }

    vector<ii> v1 = v;
    sort(v.begin(), v.end(),[](ii a, ii b){
       return a.ff<b.ff;
    });

    // for(int i = 0; i<n; i++){
    //     cout<<"["<<v[i].ff<<" "<<v[i].ss<<"] ";
    // }
    // cout<<endl;

    for(int i = 0; i<n; i++){
        int ind  = lower_bound(v.begin(), v.end(),ii{v1[i].ff, INT_MIN},[](ii a, ii b){
            return a.ff<b.ff;
        }) - v.begin();
        
        cout<<ind + v1[i].ss<<" ";
    }
}