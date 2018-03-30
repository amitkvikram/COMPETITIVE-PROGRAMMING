#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ff first
#define ss second
typedef pair< ll, ll > ii;
#define rep(i, a, b) for(ll i =a; i<b; i++)
#define pb push_back
typedef std::vector<ll> vi;
const ll mod = 1000000007;               //1e9+7

int main(){
      int n, a, b;
      cin>>n>>a>>b;
      int num = 0;
      int n1 = n;
      int a1  = (a+1)/2;
      int b1 = (b+1)/2;
      int e = a1, d = b1;
      b1 = max(e, d);
      a1 = min(e, d);
      if(a1%2) a1++;
      if(b1%2 == 0) b1--;
      if(a1==b1){
            cout<<1<<endl;
            return 0;
      }

      int c = (b1-a1+1);
      int res = 0;
      if(c%2!=0) c++;
      while(c){
            c/=2;
            res++;
      }

      if((a>(n1/2)&&b>(n1/2))|| (a<n1/2 && b<n1/2)){
            cout<<res<<endl;
      }
      else cout<<"Final!\n";
}
