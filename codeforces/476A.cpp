#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ff first
#define ss second
typedef pair< ll, ll > ii;
#define rep(i, a, b) for(ll i =a; i<b; i++)
#define pb push_back
typedef std::vector<ll> vi;
const int mod = 1000000007;               //1e9+7

int main(){
    int n, m;
    cin >> n >> m;

    int min_move = n / 2 + n % 2;       // minimum no of moves possible
    int max_move = n;                  // maximum no of moves possible

    //LOGIC: since we can take 1 or 2 steps at each move we can generate all numbers.So if m*i is between 
    //max_move and min_move we can climb n no of stairs in m moves
 
    int res = ((min_move+m-1) / m) * m;
    if (res <= max_move)
        cout << res << endl;
    else
        cout << "-1" << endl;
}