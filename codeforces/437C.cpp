#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

class edge{
public:
      int x;
      int y;
      int wt;
};

int main(){
      int n, m;
      cin>>n>>m;
      vi v(n);
      for(int i =0; i<n; i++){
            cin>>v[i];
      }

      int res = 0;
      int a, b;
      for(int i = 0; i<m; i++){
            cin>>a>>b;
            a--; b--;
            res+=(min(v[a],v[b]));
      }
      cout<<res<<endl;
}
