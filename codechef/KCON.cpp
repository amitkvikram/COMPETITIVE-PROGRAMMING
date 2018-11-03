#include <bits/stdc++.h>
using namespace std;
typedef std::vector<long long> vi;
typedef long long ll;

ll max_subarray_a(vi &v, int n){
  ll max_so_far = -1000000;
  ll max_ending_here = 0;
  for(int i =0; i<n; i++){
    max_ending_here+=v[i];
    if(max_ending_here > max_so_far) max_so_far = max_ending_here;
    if(max_ending_here<0) max_ending_here = 0;
  }
  //cout<<"Max_a: "<<max_so_far<<endl;
  return max_so_far;
}

ll max_subarray_front(vi &cum_sum, vi &v, int n){
  ll max= -1000000;
  for(int i =0; i<n; i++){
    if(cum_sum[i]>=max) max = cum_sum[i];
  }
  //cout<<"Front: "<<max<<endl;
  return max;
}

long long max_subarray_back(vi &cum_sum, vi &v, int n){
  ll max = -1000000;
  if(cum_sum[n-1]>max) max = cum_sum[n-1];
  for(int i =n-2; i>=0; i--){
    if(cum_sum[n-1]-cum_sum[i]>=max) max = (cum_sum[n-1]-cum_sum[i]);
  }
  //cout<<"back: "<<max<<endl;
  return max;
}

int main(int argc, char const *argv[]) {
  int  t;
  cin>>t;
  while(t--){
    int n, k;
    cin>>n>>k;
    vi v(n);
    vi cum_sum(n);
    cin>>v[0];
    cum_sum[0] = v[0];
    for(int i =1; i<n; i++){
      cin>>v[i];
      cum_sum[i]=cum_sum[i-1] + v[i];
    }

    ll max_a = max_subarray_a(v, n);

    if(k<=1) cout<<max_a<<'\n';

    else{
      ll res = 0;
      ll tmp1 = max_subarray_back(cum_sum, v, n);
      ll tmp2 = max_subarray_front(cum_sum, v, n);
      ll tmp3 = 0;
      if(cum_sum[n-1]>0){
         res = cum_sum[n-1]*(k-2);
         res+=std::max(tmp3,tmp1);
         res+=max(tmp3,tmp2);
      }
      else{
          res+=(tmp1+tmp2);
      }
      if(res<max_a) res = max_a;
      cout<<res<<'\n';
    }
  }
  return 0;
}
