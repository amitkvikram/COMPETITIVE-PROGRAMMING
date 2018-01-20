#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  vi v(n), sum(n,0);
  cin>>v[0]; sum[0]=v[0];
  // cout<<sum[05]<<' ';
  for(int i =1; i<n; i++){
    cin>>v[i];
    sum[i] = sum[i-1] + v[i];
    // cout<<sum[i]<<' ';
  }

  int max = 0;

  for(int i =0; i<n; i++){
    for(int j=i+1; j<n; j++){
      int cnt_1 = sum[j]-sum[i]+v[i];
      int cnt_0 = j-i+1-cnt_1;
      if(cnt_0 - cnt_1>max) max = cnt_0 - cnt_1;
    }
  }

  if(max == 0){
    for(int i =0; i<n; i++){
      if(v[i]==0){
        max =1;
        break;
      }
    }
  }

  if(max>0) cout<<sum[n-1]+max;
  else cout<<sum[n-1]-1;


  return 0;
}
