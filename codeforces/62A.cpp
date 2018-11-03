#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ff first
#define ss second
typedef pair< ll, ll > ii;
#define rep(i, a, b) for(int i =a; i<b; i++)
#define pb push_back
typedef std::vector<ll> vi;
const int mod = 1000000007;               //1e9+7

int main(){
      int g_left, g_right, b_left, b_right;
      cin>>g_left>>g_right>>b_left>>b_right;

      if(b_left>=g_right-1 && b_left<=(g_right+1)*2) cout<<"YES\n";
      else if(b_right>=g_left-1 && b_right<=(g_left+1)*2) cout<<"YES\n";
      else cout<<"NO\n";
}
