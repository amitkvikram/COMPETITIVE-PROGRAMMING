#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

// int compute(int n, vi &v){
//     int res = 0;
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < n; j++){
//             int tmp = (v[i] + v[j])/2;
//             res = res ^ (tmp);
//         }
//     }

//     return res;
// }

int main(){
    int t;
    cin >> t;
    int n;
    vi v(100000);
    while(t-- ){
        cin >> n;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            v[i] = 2 * v[i];
            res = res ^ v[i];
        }

        // cout << compute(n, v)<<"\n";

        cout << res << endl;
    }
}