#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

// set<int> v;
// set<int>::iterator it;
int n;
vi v;

int main(){
    int sum = 0, m;
    cin>>n>>m;
    v.resize(n);
    int temp;
    for(int i = 0; i < n; i++){
        cin>>v[i];
        sum+=v[i];
    }

    vector<bool> dp(sum + 1, false);
    dp[0] = true;

    for(int i = 0; i < n; i++){
        for(int j = sum - v[i]; j>=0; j--){
            dp[j + v[i]] = dp[j + v[i]] || dp[j];
        }
    }

    bool res = false;
    for(int i = 1; i <= sum; i++){
        if(i % m == 0 && dp[i] == true){
            cout<<i<<endl;
            res = true;
            break;
        }
    }
    cout<<res<<endl;
}