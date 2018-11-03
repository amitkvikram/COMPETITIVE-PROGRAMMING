#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
#define ff first
#define ss second

class exam{
    public:
    int s;
    int d;
    int c;
    int ind;
};

int main(){
    int n, m;
    cin>>n>>m;

    vector<exam> v(m);
    vi day(n, 0);
    for(int i = 0; i<m; i++){
        cin>>v[i].s>>v[i].d>>v[i].c;
        v[i].s--; v[i].d--;
        v[i].ind = i + 1;
    }

    sort(v.begin(), v.end(), [](exam l, exam r){
        if(l.d<r.d) return true;
        else return (!(l.d>r.d) && l.s<r.s);
    });

    int curr_ind = 0;
    vector<int> op;
    bool check = true;
    for(int i = 0; i<m; i++){
        day[v[i].d] = m+1;
        for(int j = v[i].s; j<v[i].d; j++){
            if(v[i].c == 0) break;
            else if(day[j] == 0){
                day[j] = v[i].ind;
                v[i].c--;
            } 
        }
        if(v[i].c>0){
            check = false;
            break;
        }
    }

    if(check == false) cout<<"-1";
    else{
        for(int i = 0; i< n; i++) cout<<day[i]<<" ";
    }
    cout<<endl;
}