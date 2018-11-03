#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;

int main(){
    int n;
    cin >> n;
    vi v(n);
    map<ll, ll> mp;
    map<ll, ll>::iterator it;
    ll res = 0, key;

    for (int i = 0; i < n; i++){
        cin >> v[i];
        it = mp.find(v[i] - 1);
        if (it == mp.end())
        {
            mp[v[i]] = 1;
            if(1 > res){
                res = 1;
                key = v[i];
            }
        }

        else{
            int tmp = it->second;
            mp[v[i]] = tmp + 1;
            if(tmp + 1> res){
                res = tmp + 1;
                key = v[i];
            }
        }
    }

    cout << res << endl;
    ll curr = key - res + 1;
    int i = 0;
    while(curr<=key){
        if(curr == v[i]){
            cout << i + 1<< ' ';
            curr++;
        }
        i++;
    }
}