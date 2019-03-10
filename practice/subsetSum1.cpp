#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

// set<int> v;
// set<int>::iterator it;
int n;
vi v;

int main(){
    int sum;
    cin>>n>>sum;
    v.resize(n);
    int temp;
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for(int i = 0; i < n; i++){
        for(int j = sum - v[i]; j >= 0; j--){
            dp[j + v[i]] = dp[j + v[i]] || dp[j];
        }
    }

    cout<<dp[sum]<<endl;
}