#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

set<int> myset;
set<int>::iterator it;

int dp[10001];

// int getCnt(int n){
//     if(n < 0){
//         return 0;
//     }
//     if(n == 0){
//         return 1;
//     }

//     if(dp[n] == -1){
//         dp[n] = getCnt(n - 1) + (n - 1)*getCnt(n - 2);
//     }
//     return dp[n];
// }

int main(){
    int n;
    cin>>n;
    // for(int i = 0; i <= n; i++){
    //     dp[i] = -1;
    // }
    // cout<<getCnt(n)<<endl;

    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + (i - 1)*dp[i - 2];
    }

    cout<<dp[n]<<endl;
}