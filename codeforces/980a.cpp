#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main(){
    string s;
    cin >> s;
    int cnt_link = 0, cnt_pearls = 0;
    for (int i = 0; i < s.size(); i++){
        if(s[i] == '-')
            cnt_link++;
        else
            cnt_pearls++;
    }

    if(cnt_pearls <=1)
        cout << "YES\n";
    else{
        if(cnt_link % cnt_pearls == 0)
            cout << "YES\n";
        else
            cout << "No\n";
    }
}