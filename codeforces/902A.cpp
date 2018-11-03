#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pr;
typedef std::vector< int > vi;

int main(int argc, char const *argv[]) {
  int n, m;
  cin>>n>>m;
  vi v(101);
  vector<int> Visited(101, 0);
  int root = 0, tmp1, tmp2;
  for(int i =0; i<101; i++){
      v[i]=0;
  }
  for(int i =0; i<n; i++){
    cin>>tmp1>>tmp2;
    if(tmp2 > v[tmp1]) v[tmp1]= tmp2;
  }

  queue<int> Q;
  int flag = 0;
  Q.push(0);
  Visited[0]=1;
  while(!Q.empty()){
    tmp1 = Q.front();
    Q.pop();
    //cout<<tmp1<<' '<<v[tmp1]<<' '<<endl;
    if(tmp1 == m){
      flag = 1;
      break;
    }
    for(int i = tmp1+1; i<=v[tmp1]; i++){
      if(Visited[i]==0){
          Q.push(i);
          Visited[i]=1;
      }
    }
  }

  if(flag == 1) cout<<"YES"<<endl;
  else std::cout << "NO"<<endl;
  return 0;
}
