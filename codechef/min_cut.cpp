#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;
int n;

void print_v(vector<vi> &v){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<v[i][j]<<' ';
        }
        cout<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    vector<vi> v(10001, vi(1000));
    ll res;
    std::set<ll>::iterator it;
    while(t--){
        cin>>n;
        for(int i = 0;  i<n; i++){
            for(int j = 0; j<n; j++){
                cin>>v[i][j];
            }
        }
        res = 0;

        for(int i  = 0; i<n; i++){
            for(int j = i+1; j<n; j++){             
                res+=max(v[i][j], v[j][i]) - min(v[i][j], v[j][i]);
                v[i][j] = v[j][i] = max(v[i][j], v[j][i]);
            }
        }
        //  cout<<res<<endl;
        // print_v(v);
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                for(int k = 0; k<n; k++){
                    if(i == k || k == j) continue;
                    if(min(v[i][k], v[k][j]) > v[i][j]){
                        // cout<<"FIrst: "<<i<<"->"<<k<<"->"<<j<<endl;
                        res+= 2*(min(v[i][k], v[k][j]) - v[i][j]);
                        v[i][j] = v[j][i] = min(v[i][k], v[k][j]);
                    }
                    // print_v(v);
                    // cout<<res<<endl;
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}