#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int MAX_N = 1000000;
bool dp[1000000] = {false};

int main(){
    int cnt1 = 1, cnt2 = 1, cnt3 = 1;
    int n;
    cin>>n;
    int minN = 1;
    n--;
    while(n){
        minN = min({cnt1*2, cnt2*3, cnt3*5});
        if(cnt1*2 == minN){
            cnt1++;
        }else if(cnt2*3 == minN){
            cnt2++;
        }else{
            cnt3++;
        }
        if(dp[minN] == false) n--;
        dp[minN] = true;
    }
    cout<<minN<<endl;
}