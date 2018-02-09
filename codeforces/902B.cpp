#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pr;
typedef std::vector< int > vi;
typedef std::vector<std::vector<int> > vii;

int coloring(int index,vi &color, int num, vii &v,vi &Visited){
  Visited[index]=1;
  int curr_clr = color[index];
  num++;
  for(auto it = v[index].begin(); it!= v[index].end(); it++){
    if(color[*it]!=curr_clr && Visited[*it] == 0) coloring(*it, color, num, v, Visited);
  }
  return num;
}

int main(int argc, char const *argv[]) {
  int n, tmp;
  std::vector< std::vector<int> > v(n,std::vector<int>(0));
  for(int i =0; i<n; i++){
    cin>>tmp;
    v[i].push_back(tmp-1);
  }

  vi color(n, 0);
  for(int i =0; i<n; i++){
    cin>>color[i];
  }

  vi Visited(n, 0);
  int min = coloring(0, color, 0, v, Visited);

  for(int i =1; i<n; i++){
    memset(&Visited[0], 0, Visited.size() * sizeof Visited[0]);
    int temp = coloring(i, color, 0, v, Visited);
    if(temp < min){
      min = temp;
    }
  }

  cout<<min;
  return 0;
}
