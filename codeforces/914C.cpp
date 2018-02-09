#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
#define PB push_back


int num_1(int n){
  int cnt = 0;
  while(n){
    if(n%2 == 1) cnt++;
    n/=2;
  }
  return cnt;
}

int main(int argc, char const *argv[]) {
  ll L = 1e7;
  string str;
  cin>>str;
  int k;
  cin>>k;
  int n = str.size();
  vi arr(n, 0);
    int count = 0;
  if(str[0]=='1'){
      arr[0]=1;
      count++;
  }
  for(int i =1; i<=n; i++){
    if(str[i]=='1'){
       arr[i]=arr[i-1]+1;
       count++;
    }
    else arr[i]=arr[i-1];
  }

  ll res = 0;

  vi s(1001, 0);
  s[1] = 0;
  for(int i =2; i<1001; i++){
    int tmp = num_1(i);
    s[i] = s[tmp]+1;
  }


  if(s[count]==k-1){
      res++;
  }

  vi fact(1001, 1);
  for(int i=1; i<1001; i++){
      fact[i] = (fact[i-1]*i)%L;
  }

  for(int i =0; i<n; i++){
    if(str[i]=='1'){
        int tmp = arr[i]-1;
        int num = n - i -1;
        for(int j = 0; j<=num; j++){
          if(s[j+tmp] == k-1){

              int tmp1 = (fact[num]/(fact[j]*fact[num-j]))%L;
              //cout<<"tmp1: "<<tmp1<<endl;
              res = (res%L+tmp1)%L;
              //cout<<"i:"<<i<<" "<<"num: "<<num<<' '<<"j: "<<j<<' '<<"tmp: "<<tmp<<"s[i]: "<<s[num+tmp]<<endl;
          }
        }
    }
  }

   cout<<res<<endl;
  return 0;
}
