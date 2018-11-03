#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef pair< string,vi> pr;

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  vi v1 = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  vi v2 = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  vi v3 = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30,31, 30 , 31};
  vi v4 = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  vi v(n);
  for(int i =0; i<n; i++){
    cin>>v[i];
  }

  int flag = 0;
  //search in v1
  for(int i =0; i< 36- n; i++){
    int cnt = 0;
    for(int j =0; j<n; j++){
      if(v[j]==v1[j+i]) cnt++;
    }
    if(cnt == n){
      flag  = 1;
      break;
    }
  }

  //if no t found search in v2
  if(flag == 0){
    for(int i =0; i< 36- n; i++){
      int cnt = 0;
      for(int j =0; j<n; j++){
        if(v[j]==v2[j+i]) cnt++;
      }
      if(cnt == n){
        flag  = 1;
        break;
      }
    }
  }

  if(flag == 0){
    for(int i =0; i< 36- n; i++){
      int cnt = 0;
      for(int j =0; j<n; j++){
        if(v[j]==v3[j+i]) cnt++;
      }
      if(cnt == n){
        flag  = 1;
        break;
      }
    }
  }

  if(flag == 0){
    for(int i =0; i< 36- n; i++){
      int cnt = 0;
      for(int j =0; j<n; j++){
        if(v[j]==v4[j+i]) cnt++;
      }
      if(cnt == n){
        flag  = 1;
        break;
      }
    }
  }

  if(flag == 1) cout<<"YES";
  else cout<<"NO";
  return 0;
}
