#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vi S(1000);

int getCnt(int m, int n){
    if(n == 0){
        return 1;
    }
    if(n < 0 || m == 0){
        return 0;
    }

    return getCnt(m, n - S[m - 1]) + getCnt(m - 1, n);
}

int main(){
    int m, n;

    cin>>n;
    cin>>m;
    for(int i = 0; i < m; i++){
        cin>>S[i];
    }

    // cout<<getCnt(m, n)<<endl;
    vector<int> table(n + 1, 0);
    table[0] = 1;

    for(int j = 0; j < m; j++){
        for(int i = 1; i <= n; i++){
            if(i - S[j] >= 0){
                table[i] += table[i - S[j]];
            }
        }
    }

    cout<<table[n]<<endl;
}