#include<bits/stdc++.h>
using namespace std;

typedef vector<long long> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int>> iii;
#define ff first
#define ss second 
const int inf = 1e9+7;
#define rep(i, a, b) for(int i = a; i < b; i++)
typedef long long ll;


int row_num[] = {0, 0, -1, 1, -1, -1, 1, 1};
int col_num[] = {-1, 1, 0, 0, -1, 1, -1, 1};

int n;
vector<vi> v(300, vi(300));

ll getSum(){
    ll sum1 = 0;
    rep(i, 0, n){
        rep(j, i + 1, n){
            sum1+=v[i][j];
        }
    }

    return sum1;
}


int main(){  
    cin>>n;
    rep(i, 0, n){
        rep(j, 0, n){
            cin>>v[i][j];
        }
    }

    int k;
    cin>>k;
    ll a, b, c;
    while(k--){
        cin>>a>>b>>c;
        a--; b--;
        v[a][b] = min(v[a][b], c);
        v[b][a] = min(v[b][a], c);
        vector<ll> temp = {a, b};
        for(int elem:temp){
            rep(i, 0, n){
                rep(j, 0, n){
                    v[i][j] = min(v[i][j], v[i][elem] + v[elem][j]);
                }
            }
        }
        cout<<getSum()<<" ";
    }
    cout<<endl;
}