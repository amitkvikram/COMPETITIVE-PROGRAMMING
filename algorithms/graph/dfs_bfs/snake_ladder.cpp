#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int min_throw(std::vector<int> &v, int n){
      int source = 0, destination = n-1, count = 0;
      queue<int> q;
      q.push(source);
      vi level(n, 0);
      std::vector<bool> visited(n, false);
      visited[source] = true;
      while(!q.empty()){
            source = q.front();
            q.pop();
            if(destination == source){
                  return level[n-1];
            }
            for(int i = source+1; i<n && i<source+7; i++){
                  if(visited[i] == false){
                        visited[i] = true;
                        if(v[i] == -1){
                              q.push(i);
                              level[i] = level[source] + 1;
                        }
                        else{
                              q.push(v[i]);
                              level[v[i]] = level[source] + 1;
                         }
                  }
            }
      }
      return -1;
}

 int main(){
       int n;
       cin>>n;
       vi v(n);
       for(int i =0; i<n; i++){
             v[i]  = -1;
       }

       int a, b , m;
       cin>>m;
       for(int i = 0; i<m; i++){
             cin>>a>>b;
             v[a] = b;
       }
       cout<<min_throw(v, n)<<endl;
 }
