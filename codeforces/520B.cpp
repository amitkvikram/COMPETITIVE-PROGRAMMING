#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

void bfs(int n, int m, int &count){
      queue<int> q;
      q.push(n);
      vi level(20001, 0);
      vi visited(20001, false);
      visited[n]==true;
      //vi visited()
      while(!q.empty()){
            int i = q.front();
            q.pop();
            //cout<<i<<","<<level[i]<<' ';
            if(i == m) break;
            int tmp1 = i*2;
            int tmp2 = i-1;
            if(tmp1>0 && tmp1<20001 && visited[tmp1] == false){
                visited[tmp1] = true;
                level[tmp1] = level[i]+1;
                q.push(tmp1);
            }
            if(tmp2>0 && visited[tmp2] == false){
                visited[tmp2] = true;
                q.push(tmp2);
                level[tmp2] = level[i]+1;
            }

      }
      count = level[m];
}

int main(){
      int n, m;
      cin>>n>>m;
      int count = 0;
      bfs(n, m, count);
      cout<<count<<endl;
}
