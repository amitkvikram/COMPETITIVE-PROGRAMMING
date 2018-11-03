#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
int t;
cin>>t;
while(t--){
  int n, m;
  cin>>n>>m;

  int num1 = 0, num2 =0;

  vector< vector<char> > v(n, vector<char>(m));

  for(int i =0; i<n; i++){
    for(int j =0; j<m; j++){
      cin>>v[i][j];
    }
  }

  for(int i =0;i<n; i+=2){
    for(int j =0; j<m; j+=2){
      if(v[i][j] == 'G') num1+=3;
      if(v[i][j] == 'R') num2+=5;
    }

    for(int j =1; j<m; j+=2){
      if(v[i][j] == 'R') num1+=5;
      if(v[i][j] == 'G') num2+=3;
    }
  }

  for(int i =1;i<n; i+=2){
    for(int j =0; j<m; j+=2){
      if(v[i][j] == 'R') num1+=5;
      if(v[i][j] == 'G') num2+=3;
    }

    for(int j =1; j<m; j+=2){
      if(v[i][j] == 'G') num1+=3;
      if(v[i][j] == 'R') num2+=5;
    }
  }

  cout<<min(num1, num2)<<endl;

}
}
