#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<list<int>> vl;

int main(){
      int n,  m;
      cin>>n>>m;
      vi v(n, 0);
      int a, b;
      for(int i =0; i<m; i++){
            cin>>a>>b;
            a--; b--;
            v[a] = 1;
            v[b] = 1;
      }

      int ind;
      for(int i =0; i<n; i++){
            if(v[i]==0) ind = i;
      }
      cout<<n-1<<endl;
      for(int i =0; i<n; i++){
            if(i!=ind){
                  cout<<i+1<<' '<<ind+1<<endl;
            }
      }

}
