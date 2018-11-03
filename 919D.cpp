#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<pair<char, bool>> vi;
typedef std::vector< list<int> > vvi;

void dfs(vi &v,vvi &adjList, int i, std::vector<int> &tmp){
      v[i].second = true;
      tmp[v[i].first-'a']++;
      for(auto j = adjList[i].begin(); j!=adjList[i].end(); j++){
            if(v[*j].second == false){
                  dfs(v, adjList, *j, tmp);
            }
      }
}

int main(int argc, char const *argv[]) {
      int n, m;
      cin>>n>>m;
      string str;
      cin>>str;
      std::vector<pair<char, bool>> v(n);
      for(int i =0; i<n; i++){
            v[i] = {str[i],false};
      }

      std::vector< list<int> > adjList(n, list<int>());
      int a, b;
      for(int i =0;i<m; i++){
            cin>>a>>b;
            adjList[a].push_back(b);
      }
      int res = 0;
      for(int i =0; i<n;i++){
            if(!v[i].second){
                  std::vector<int> tmp(26, 0);
                  dfs(v, adjList, i, tmp);
                  auto temp = max_element(tmp.begin(), tmp.end());
                  if( *temp > res){
                        res = *temp;
                  }
            }
      }
      return 0;
}
