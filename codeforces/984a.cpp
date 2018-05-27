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

int row[] = {0, 0, 1, 1, 1, -1, -1, -1};
int col[] = {1, -1, 0, 1, -1, 0, 1, -1};

bool isvalid(int i, int j, int n, int m){
    return i>=0 && j>=0 && i<n && j<m;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
    int n, q;
    cin>>n;
    vi v(n);
    int dp[n][n];
    rep(i, 0, n){
        cin>>v[i];
        dp[0][i] = v[i];
    }

    for(int i = 1; i<n; i++){
        for(int j = 0; j<n - i; j++){
            dp[i][j] = dp[i - 1][j]^dp[i-1][j+1];
        }
    }

    for(int i  = 1; i<n; i++){
        for(int j = 0; j<n - i; j++){
            dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i-1][j+1]));
        }
    }

    cin>>q;
    while(q--){
        int l, r;
        cin>>l>>r;
        l--; r--;
        cout<<dp[r-l][l]<<endl;
    }
}