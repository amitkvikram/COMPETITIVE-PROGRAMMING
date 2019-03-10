#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

// set<int> v;
// set<int>::iterator it;
int n;
vi v;

vector<vector<bool>> dp(100, vector<bool>(1000));

bool checkSum(int i, int sum){
    if(sum == 0) return true;
    if(sum < 0 || i >= n) return false;
    if(dp[i][sum] != -1){
        return dp[i][sum];
    }
    dp[i][sum] = checkSum(i + 1, sum) || checkSum(i + 1, sum - v[i]);
    return dp[i][sum];
}

int main(){
    int sum;
    cin>>n>>sum;
    v.resize(n);
    int temp;
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    // cout<<checkSum(0, sum)<<endl;
    for(int i = 0; i < n; i++){
        dp[i][0] = true;
    }

    for(int i = 1; i < n; i++){
        dp[0][i] = false;
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= sum; j++){
            if(j >= v[i]){
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - v[i]];
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout<<dp[n - 1][sum]<<endl;
}