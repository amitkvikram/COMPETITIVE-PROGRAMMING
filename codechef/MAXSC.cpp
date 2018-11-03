#include <bits/stdc++.h>
using namespace std;
typedef std::vector<int> vi;

bool compare(int a, int b){
  return a>b;
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    std::vector< std::vector<long long> > v(n, std::vector<long long>(n, 0));
    for(int i =0; i<n; i++){
      for(int j =0; j<n; j++){
        cin>>v[i][j];
      }
      sort(v[i].begin(), v[i].end());
    }

    long long temp = v[n-1][n-1], flag = 1;
    long long sum =temp;
    for(int i = n-2; i>=0; i--){
      int index = lower_bound(v[i].begin(), v[i].end(), temp) - v[i].begin();
      if(index == 0 ){
        flag = 0;
        break;
      }
      sum+=v[i][index-1];
      temp = v[i][index-1];
    }
    if(flag == 0) std::cout << "-1" << '\n';
    else cout<<sum<<endl;
  }
  return 0;
}
