#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
int n, m;
vector<vi> v;

bool isValid(int i, int j){
    return i >= 0 && j >= 0 && i <n  && j < m;
}

int getGold(int i, int j){
    if(!isValid(i, j)){
        return 0;
    }
    int res = v[i][j];
    return res + max({getGold(i, j + 1), getGold(i+1, j+1), getGold(i - 1, j + 1)});
}

int main(){
    cin>>n>>m;
    v.resize(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>v[i][j];
        }
    }

    vector<vector<int>> cnt(n + 2, vector<int>(m + 2, 0));

    int res = 0;

    for(int j = m; j > 0; j--){
        for(int i = n; i > 0; i--){
            cnt[i][j] = v[i-1][j-1] + max({cnt[i + 1][j + 1], cnt[i][j+1], cnt[i - 1][j + 1]});
        }
    }

    for(int i = 1; i <= n; i++){
        res = max(res, cnt[i][1]);
    }

    cout<<res<<endl;
}