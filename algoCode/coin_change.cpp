#include<bits/stdc++.h>
using namespace std;

int cnt1 = 0;
int cnt2 = 0;
//Brute Force
int coin_change(int ind, int money, vector<int> &c){
    cnt1++;
    if (money == 0)
    {
        return 1;
    }

    if(money < 0)
        return 0;

    if(ind>c.size() - 1)
        return 0;

    return coin_change(ind + 1, money, c) + coin_change(ind, money - c[ind], c);
}

//memoization with space complexity: O(mn)
int coin_change(int ind, int money, vector<int> &c, vector<vector<int>> &v){
    cnt2++;
    if (money == 0)
    {
        return 1;
    }

    if(money < 0)
        return 0;

    if(ind>c.size() - 1)
        return 0;
    
    if(v[money][ind]!=-1)
        return v[money][ind];
    v[money][ind] = coin_change(ind + 1, money, c, v) + coin_change(ind, money - c[ind], c, v);
    return v[money][ind];
}

//Bottom up
int coin_change(int money, vector<int> &c){
    vector<vector<int>> v(money + 1, vector<int>(c.size(), 0));

    for (int i = 0; i <= money; i++){
        for (int j = 0; j < c.size(); j++){
            if (i == 0)
            {
                v[i][j] = 1;
            }

            else if(j == 0){
                if(i >= c[j]){
                    v[i][j] += v[i - c[j]][j];
                }
            }

            else{
                v[i][j] = v[i][j - 1];
                if(i - c[j]>=0)
                    v[i][j] += v[i - c[j]][j];
            }
        }   
    }
    cout << v[money][c.size() - 1] << endl;
}

int main(){
    int money;
    cin >> money;
    int n; // number of distinct coin
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++){
        cin >> c[i];
    }

    // vector<vector<int>> v(money + 1, vector<int>(n, -1));
    // cout << coin_change(0, money, c)<<"\nnum_call = "<<cnt1<<endl;
    // cout << coin_change(0, money, c, v)<<"\nnum_call = "<<cnt2<<endl;
    coin_change(money, c);
}