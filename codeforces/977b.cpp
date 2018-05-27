#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int compute(string &src, string curr){
    int cnt = 0;
    for (int i = 0; i < src.size() - 1; i++){
        if(src.substr(i, 2) == curr)
            cnt++;
    }
    return cnt;
}

int main(){
    int n;
    string s;
    cin >> n >> s;
    string res;

    int max_l = 0;
    for (int i = 0; i < n - 1; i++){
        int tmp = compute(s, s.substr(i, 2));
        if (tmp> max_l){
            max_l = tmp;
            res = s.substr(i, 2);
        }
    }

    cout << res << endl;
}