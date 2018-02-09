#include <bits/stdc++.h>
using namespace std;

typedef std::vector<int> vi;
typedef long long ll;

int main(int argc, char const *argv[]) {
  int n, q;
  cin>>n>>q;
  vi a(n), p(n);
  vector< vector<int> > freq(333, vector<int>(1000005, 0));
  cin>>a[0];
  p[0] = a[0];
  int sz = 1000;
  int sz1= (n-0.1)/sz+1;
  // cout<<sz<<' '<<sz1<<endl;
  // cout<<p[0]<<' ';
  for(int i =1; i<n; i++){
    cin>>a[i];
    p[i] = p[i-1]^a[i];
    // cout<<p[i]<<' ';
  }

  vi v(sz, 0), t(sz, 0);

  for(int i =0; i<n; i++){
    freq[i/sz][p[i]]++;
  }

  int fg, i, b;
  while(q--){
    cin>>fg>>i>>b;
    i-=1;
    if(fg==1){
      int c = b^a[i];
      for(int j = i; j<(i/sz+1)*sz && j<n; j++){
        // cout<<"j="<<j<<' ';
        freq[i/sz][p[j]]-=1;
        p[j]= p[j]^c;
        freq[i/sz][p[j]]++;
      }
      for(int j = (i/sz+1); j<sz1; j++){
        t[j] = t[j]^c;
      }
      a[i] = b;
      // cout<<endl;
      // for(int j =0; j<n; j++){
      //   cout<<a[j]<<' ';
      // }
      // cout<<endl;
      // for(int j =0; j<n; j++){
      //   cout<<p[j]<<' ';
      // }
      // cout<<endl<<t[0]<<' '<<t[1]<<endl;
    }

    else{
      int sum =0;
      for(int j =0; j<i/sz; j++){
        sum+=freq[j][(b^t[j])];
      }
      // cout<<sum<<endl;
      for(int j =(i/sz)*sz; j<i+1; j++){
        // cout<<' '<<p[j]<<' '<<t[i/sz]<<endl;
        if((p[j]^t[i/sz]) == b) sum++;
      }
      cout<<sum<<endl;
    }
  }
  return 0;
}
