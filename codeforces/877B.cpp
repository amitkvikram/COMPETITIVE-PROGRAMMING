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
      string str;
      cin>>str;
      int curr_a = 0, curr_s = 0, num = 0;
      vector<ii> cnt(str.size());

      if(str[0] == 'a'){
            cnt[0].ff = 1;
            cnt[0].ss = 0;
      }
      else{
            cnt[0].ff = 0;
            cnt[0].ss = 1;
      }

      rep(i, 1, str.size()){
            if(str[i] == 'a'){
                  cnt[i].ff = cnt[i-1].ff+1;
                  cnt[i].ss = cnt[i-1].ss;
            }

            else{
                  cnt[i].ss = cnt[i-1].ss + 1;
                  cnt[i].ff = cnt[i-1].ff;
            }
      }

      int n = str.size();
      int a, b, c;
      rep(i, 0, n){
            rep(j, i+1, n){
                  a = cnt[i].ff;

                  b = cnt[j].ss - cnt[i].ss;

                  c = cnt[n-1].ff - cnt[j].ff;
                  int temp = (a)  + (b) + (c);
                  if (temp>num)  num = temp;
            }
      }

      // a= 0 no a in beginning
      rep(j, 0, n){
            a = 0;
            b = cnt[j].ss;
            c = cnt[n-1].ff - cnt[j].ff;
            int temp = a+b+c;
            // cout<<a<<' '<<b<<' '<<c<<endl;
            if(temp>num) num = temp;
      }

      //b=0
      if(cnt[n-1].ff>num) num = cnt[n-1].ff;

      // //c = 0
      // rep(i, 0, n){
      //       c = 0;
      //       a = cnt[i].ff;
      //       b = cnt[n-1].ss - cnt[]
      // }
      cout<<num<<endl;
}
