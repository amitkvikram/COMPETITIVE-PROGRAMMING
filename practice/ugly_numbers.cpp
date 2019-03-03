#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int MAX_N = 1000000;
int dp[1000000];
bool ugly[1000000] = {false};

int main(){
    int cnt1 = 1, cnt2 = 1, cnt3 = 1;
    int n;
    cin>>n;
    int minN = 1;
    dp[1] = 1;
    int i = 1;
    while(i < n){
        minN = min({dp[cnt1]*2, dp[cnt2]*3, dp[cnt3]*5});
        if(dp[cnt1]*2 == minN){
            cnt1++;
        }else if(dp[cnt2]*3 == minN){
            cnt2++;
        }else{
            cnt3++;
        }
        if(!ugly[minN]){
            i += 1;
            dp[i] = minN;
        }
        ugly[minN] = true;
    }
    cout<<minN<<endl;
}