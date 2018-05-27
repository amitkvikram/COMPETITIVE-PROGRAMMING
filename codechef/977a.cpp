#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;



int main(){
    ll n, k;
    cin >> n >> k;

    while(k--){
        if(n%10 == 0)
            n /= 10;
        else
            n -= 1;
    }
    cout << n << endl;
}