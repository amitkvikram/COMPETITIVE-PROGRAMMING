#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;


bool isPalin(string s){

    int n = s.size();

    for (int i = 0; i < n/2; i++){
        if(s[i] != s[n - 1 - i])
            return false;
    }

    return true;
}

vector<vector<int>> dp(100, vector<int>(100, -1));

int countAllPalindromicSubstring(string s, int l, int r){
    // if(dp[l][r] != -1)
    //     return dp[l][r];
    // cout << l << " " << r << endl;
    if (l == r)
        return 0;
    if (r == l + 1)
    { //if string lenght is 2
        if(s[l] == s[r]){
            dp[l][r] = 1;
            return 1;
        }
        else{
            dp[l][r] = 0;
            return 0;
        }
    }

    string currS = s.substr(l, r - l + 1);
    bool isPalin1 = isPalin(currS);
    int tmp1 = countAllPalindromicSubstring(s, l + 1, r);
    int tmp2 = countAllPalindromicSubstring(s, l, r - 1);
    int tmp3 = countAllPalindromicSubstring(s, l + 1, r - 1);
    // cout << currS << " " << tmp1 << " " << tmp2 << " " << tmp3 << endl;
    if (isPalin1)
    {
        // dp[l][r] =
        dp[l][r] = tmp1 + tmp2 - tmp3 + 1;
    }
    else{
        dp[l][r] = tmp1 + tmp2 - tmp3;
    }

    return dp[l][r];
}

int main(){
    string s;
    cout << "Enter String: ";
    cin >> s;
    cout << countAllPalindromicSubstring(s, 0, int(s.size()) - 1) << endl;
    cout << dp[0][s.size() - 1]<<endl;
}