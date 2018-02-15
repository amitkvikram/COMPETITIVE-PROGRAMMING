#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int product(int num){
      int p = 1;
      while(num){
            if(num%10!=0){
                  p =p * ((num)%10);
            }
            num/=10;
      }
      return p;
}

int query(vi &g, int num){
      //cout<<num<<' ';
      if(num<10 || g[num]!=0){
          return g[num];
      }
      else{
            int p = product(num);
            int tmp = query(g, p);
            g[num] = tmp;
            return tmp;
      }
}

int main(){
       vi g((1e6)+1 , 0);
      int sz = (int)sqrt(1e6);
      vector<vector<int>> cnt(sz+1, vector<int>(10, 0));
      for(int i = 1; i<10; i++){
            g[i] = i;
      }
      for(int i =1e6; i>=1; i--){
            if(g[i] == 0){
                  g[i] = query(g, i);
            }
            cnt[i/sz][g[i]]++;
      }

      int q;
      cin>>q;
      int l, r, k;
      while(q--){
            cin>>l>>r>>k;
            int i, count = 0;
            for(int i =l; i<=r; i++){
                if(i%sz == 0 && r/sz>i/sz){
                    count+=cnt[i/sz][k];
                    i+=(sz-1);
                }

                else{
                    if(g[i] == k) count++;
                }
            }

            cout<<count<<endl;
      }
}
