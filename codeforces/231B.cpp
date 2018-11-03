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
      int n, d, l;
      cin>>n>>d>>l;
      int n1 = n/2;
      int Min, Max;
      if(n%2 == 0){
            Max = n1*(l-1);
            Min = -Max;
      }
      else{
            Max = (n1+1)*l-(n1);
            Min = n1+1 - (n1)*l;
      }

      if(d<=Max && d>=Min){
            vi v(n);
            rep(i, 0, n){
                  if(i%2 == 0) v[i] = l;
                  else v[i]=1;
            }
            int x = Max;
            for(int i =0; i<l-1; i++){
                if(x==d) break;
                  rep(i, 0, n){
                        if(x==d) break;
                        if(i%2!=0){
                              v[i]++;
                              x--;
                        }
                  }
            }
            if(x!=d){
                  for(int i =0; i<l-1; i++){
                        if(x==d) break;
                        rep(i, 0, n){
                              if(x==d) break;
                              if(i%2==0){
                                    v[i]--;
                                    x--;
                              }
                        }
                  }
            }

            for(auto i:v){
                cout<<i<<' ';
            }
      }
      else cout<<"-1"<<endl;
}
