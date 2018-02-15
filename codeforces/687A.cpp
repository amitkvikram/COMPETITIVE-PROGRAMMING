#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef vector<vector<int>> vvi;

bool dfs(std::vector<list<int>> &v, vvi &vc, vi &color, int s){
      vc[color[s]].push_back(s);
      for(auto it = v[s].begin(); it!=v[s].end(); it++){
            if(color[*it] == color[s]) return false;
            if(color[*it] == -1){
                  color[*it] = 1-color[s];
                  if(!(dfs(v, vc, color, *it))) return false;
            }
      }
      return true;
}

void vertex_cover(std::vector<list<int>> &v, int n){
      vi color(n, -1);
      vvi vc(2, vi());
      for(int i=0; i<n; i++){
            if(color[i] != -1) continue;
            if(!(v[i].empty())){
                  color[i] = 0;
                  if(!(dfs(v, vc, color, i))){
                        cout<<"-1"<<endl;
                        return;
                  }
            }
      }

      cout<<vc[0].size()<<endl;
      for(int i =0; i<vc[0].size(); i++){
          cout<<vc[0][i]+1<<' ';
      }
      cout<<endl;
      cout<<vc[1].size()<<endl;
      for(int i =0; i<vc[1].size(); i++){
        cout<<vc[1][i]+1<<' ';
      }
}

int main(){
      int n, m;
      cin>>n>>m;

      std::vector<list<int>> v(n, list<int>());

      int a, b;
      for(int i =0; i<m; i++){
            cin>>a>>b;
            a--; b--;
            v[a].push_back(b);
            v[b].push_back(a);
      }

      vertex_cover(v, n);
}
