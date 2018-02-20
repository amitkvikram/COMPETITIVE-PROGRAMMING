#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<ll> vi;
ll MAX = 1e9+7;

int main(){
      int n;
      cin>>n;
      std::vector<int> v(n);
      int count = n;
      vi cnt(1e6+1, 0);
      for(int i =0; i<n; i++){
            cin>>v[i];
            cnt[v[i]] = 1;
      }

      int a = 1, b= 1e6;
    if(cnt[1]==1) cnt[1] = 0;
    if(cnt[b] == 1) cnt[b]=0;
    a++; b--;
      int res = 0;
      while(count!=0){
            if(cnt[a] == 1){
                  count--;
            }
            if(cnt[b] == 1){
                  count--;
            }
             res++;
             a++;
             b--;
             if(count == 0) break;
      }
      cout<<res<<endl;

}
