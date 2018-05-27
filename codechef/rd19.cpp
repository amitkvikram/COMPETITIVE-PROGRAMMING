#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a==0)
        return b;
    return gcd(b % a, a);
}

int main(){
    int t;
    cin >> t;
    int n, res;
    vector<int> v(1000);
    while (t--)
    {
        cin >> n;
        cin >> v[0];
        res = v[0];
        for (int i = 1; i < n; i++)
        {
            cin >> v[i];
            res = gcd(res, v[i]);
        }

        // cout << res << endl;

        if(res == 1)
            cout << "0" << endl;
        else
            cout << "-1\n";
    }
}