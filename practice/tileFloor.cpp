#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int n, m;

int getCnt(int i){
    if(i >= n){
        return 1;
    }

    if( i <= n - m){
        return getCnt(i + 1) + getCnt(i + m);
    }else{
        return 1;
    }
}

int main(){
    cin>>n>>m;

    // cout<<getCnt(0)<<endl;
    int cnt[n + 1];
    for(int i = 1; i <= n + 1; i++){
        if(i < m){
            cnt[i] = 1;
        }
        else if(i == m){
            cnt[i] = 2;
        }
        else{
            cnt[i] = cnt[i - m] + cnt[i - 1];
        }
    }

    cout<<cnt[n]<<endl;
}