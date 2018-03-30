#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ff first
#define ss second
typedef pair< int, int > ii;
#define rep(i, a, b) for(ll i =a; i<b; i++)
#define pb push_back
typedef std::vector<double> vi;
// const floatmod = 1000000007;               //1e9+7

vi row_num = {-1, 0, 1, 0};
vi col_num = {0,-1, 0, 1};

bool check(vi &v, int gap, int mult, int k){
      vector<ii> tmp;
      rep(i, 0, k){
            if(gap != (v[k] - v[i])*mult) tmp.pb({i, v[i]});
      }
      rep(i, k+1, v.size()){
            if(gap*(i-k) != (v[i] - v[k]) *mult) tmp.pb({i, v[i]});
      }
      // cout<<tmp.size()<<endl;
      if(tmp.size() == 0) return false;
      else if(tmp.size() == 1) return true;
      else{
            int gap1 = tmp[1].ss - tmp[0].ss;
            int mult1 = tmp[1].ff - tmp[0].ff;
            // cout<<tmp[1].ff<<' '<<tmp[0].ff<<' '<<gap1<<' '<<mult1<<' '<<gap<<' '<<mult<<endl;
            int x = tmp[0].ff;
            int y = tmp[0].ss;
            if(gap*mult1 != gap1*mult) return false;
            rep(i, 1, tmp.size()){
                  if(gap1 * (tmp[i].ff - x) != mult1*(tmp[i].ss - y)) return false;
            }
            return true;
      }
}

int main(){
      int n;
      cin>>n;
      vi v(n);
      rep(i, 0, n) cin>>v[i];
      bool flag = false;
      //one of the line has v[0], v[1]
      flag|= check(v, v[1] - v[0], 1, 0);
      //one of the line has v[1],v[2]
      flag|= check(v, v[2] - v[1], 1, 1);
      //one of the line has v[0], v[2]
      flag|= check(v, v[2] - v[0], 2, 0);

      if(flag == true) cout<<"Yes\n";
      else cout<<"No\n";
}
