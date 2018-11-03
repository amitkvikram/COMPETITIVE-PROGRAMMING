#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main(){
    int n, k;
    cin >> n >> k;
    vi v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    
    if(k > n )
        cout << "-1\n";
    else{
        if(k == 0){
            if(v[0] > 1)
                cout << v[0] - 1;
            else
                cout << "-1\n";
        }
        else{
            if(v[k-1] <= 1e9 &&(k>=n || v[k]!=v[k-1]))
                cout << v[k - 1] << endl;
            else
                cout << "-1\n";
        }
    }
}