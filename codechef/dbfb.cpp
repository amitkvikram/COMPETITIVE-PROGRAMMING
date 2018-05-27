#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;

const ll mod = 1e9 + 7;

int main(){
    int t;
    cin >> t;

    vi fib(100000);
    fib[0] = 1;
    fib[1] = 1;

    for (int i = 2; i < 100000; i++){
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    }

    // for (int i = 1; i < 100000; i++){
    //     fib[i] = (fib[i - 1] + fib[i]) % mod;
    // }

    while(t--){
        ll m,n;
        cin >> m>>n;
        vi a(m), b(m);
        ll sum_a = 0, sum_b = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
            sum_a = (sum_a + a[i]) % mod;
        }

        for (int i = 0; i < n; i++){
            cin >> b[i];
            sum_b = (sum_b + b[i]) % mod;
        }

        // cout << sum_a << ' ' << sum_b << endl;

        if(n>2){
            cout << (m * (((sum_a * fib[n - 3]) % mod + (sum_b * fib[n - 3]) % mod)) % mod) % mod << endl;
        }
        else if(n == 2){
            cout << (m * sum_b) % mod<< endl;
        }
        else{
            cout << (m * sum_a) % mod<< endl;
        }
    }
}