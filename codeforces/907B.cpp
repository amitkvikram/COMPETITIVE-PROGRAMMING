#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef pair< string,vi> pr;

int main(int argc, char const *argv[]) {
  std::vector< std::vector<string> > v(9,std::vector<string>(3));
  for(int i = 0; i<9; i++){
    for(int j = 0; j<3; j++) cin>>v[i][j];
  }

    int l, m;
  cin>>l>>m;
  l--; m--;
  int l1 = l%3, m1= m%3;

  //cout<<l1<<' '<<m1<<endl;

  int flag = 0;
  for(int i = l1*3; i<(l1+1)*3; i++){
      for(int j = 0; j<3; j++){
          if((v[i][m1])[j] == '.'){
              v[i][m1][j]='!';
              flag = 1;
          }
      }
  }

  if(flag != 1){
      for(int i =0; i<9; i++){
          for(int j =0; j<3 ;j++){
              if(j==m1 && (i<(l1+1)*3 && i>=l1*3)) continue;
              else{
                  for(int k =0; k<3; k++){
                      if(v[i][j][k] == '.') v[i][j][k]='!';
                  }
              }
          }
      }
  }

  for(int i = 0; i<9; i++){
    for(int j = 0; j<3; j++) cout<<v[i][j]<<' ';
    cout<<endl;
    if(i%3==2) cout<<endl;
  }
  return 0;
}
