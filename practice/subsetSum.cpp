#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

// set<int> v;
// set<int>::iterator it;
int n;
vi v;

vector<vi> dp(100, vi(1000, -1));

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

    
}