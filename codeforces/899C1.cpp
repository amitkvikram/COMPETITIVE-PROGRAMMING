#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<ll> vi;
typedef pair< string,vi> pr;


int main(int argc, char const *argv[]) {
  ll n;
  cin>>n;
  ll sum1 = (n*(n+1))/2;
  ll sum = sum1/2;
  // cout<<sum<<endl;
  ll tmp =0;
  if(sum1%2==0)  tmp =1;
  // cout<<"n="<<n<<endl;
  vi v;
  if(tmp == 1){
    cout<<'0'<<endl;
    for(int i =n; i>0;i-- ){
      if(sum == 0) break;
      if(sum>=i){
        sum-=i;
        v.push_back(i);
      }
    }
  }

  else{
    sum+=1;
    cout<<'1'<<endl;
    for(int i =n; i>0;i--){
      // cout<<i<<endl;
      if(sum == 0) break;
      if(sum>=i){
        sum-=i;
        v.push_back(i);
      }
    }
  }

  cout<<v.size()<<' ';
  int temp = 0;
  for(int i =0; i<v.size(); i++){
    cout<<v[i]<<' ';
  }
  return 0;
}
