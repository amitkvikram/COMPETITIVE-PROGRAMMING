#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

class edge{
public:
      int ind;
      int wt;
};

void dfs(vector<list<edge>> &v, vi &city, vi &visited, int s, int ind){
     //cout<<s<<endl;
      visited[s] = 1;
      for(auto it = v[s].begin(); it!=v[s].end(); it++){
          if(visited[(*it).ind] == 0){

                if((*it).wt == 2){
                      city[ind] = 0;
                      city[(*it).ind] = 1;
                      dfs(v, city, visited, (*it).ind, (*it).ind);
                }
                else{
                      dfs(v, city, visited, (*it).ind, ind);
                }
          }
      }
}

void get_city(vector<list<edge>> &v, vi &city, int n){
      vi visited(n, 0);
      city[0] = 1;
      dfs(v, city, visited, 0, 0);

      int count = 0;
      for(int i =1; i<n; i++){
            if(city[i]==1){
                  count++;
            }
      }
      cout<<count<<endl;
      for(int i = 1; i<n; i++){
            if(city[i]==1){
                  cout<<i+1<<' ';
            }
      }
      //cout<<endl;
}

int main(){
      int n;
      cin>>n;
      int a, b , t;
      std::vector<list<edge>> v(n);
      for(int i =1; i<n; i++){
            cin>>a>>b>>t;
            a--; b--;
            v[a].push_back({b, t});
            v[b].push_back({a, t});
      }

      vi city(n, 0);
      get_city(v, city, n);
}
