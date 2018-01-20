#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  int m, n;
  cin>>m>>n;
  std::vector< vector<int> > B(m, std::vector<int>(n));
  std::vector< vector<int> > A(m, std::vector<int>(n, 1));
  vi row(m, 0), col(n, 0);
  for(int i =0; i<m; i++){
    for(int j =0; j<n; j++){
      cin>>B[i][j];
      if(B[i][j]==0){
        row[i]=1;
        col[j]=1;
      }
    }
  }

  for(int i =0; i<m; i++){
    if(row[i] == 1){
      // cout<<"i="<<i<<endl;
      for(int j =0; j<n; j++){
        A[i][j]=0;
      }
    }
  }

  for(int j=0; j<n; j++){
    if(col[j]==1){
      // cout<<"j="<<j<<endl;
      for(int i =0; i<m; i++){
        A[i][j]=0;
      }
    }
  }
  int flag = 0;
  for(int i=0; i<m; i++){
    for(int j =0; j<n; j++){
      if(B[i][j] == 1){
        int flag1 = 0;
        for(int l = 0; l<n; l++){
          if(A[i][l]==1) flag1=1;
        }
        if(flag1==0){
          for(int k=0; k<m; k++){
            if(A[k][j]==1) flag1 =1;
          }
        }
        if(flag1==0){
          flag = 1;
          break;
        }
      }
    }
  }

  if(flag == 1) cout<<"NO";
  else{
    cout<<"YES"<<endl;
    for(int i =0; i<m; i++){
      for(int j =0;j<n; j++){
        cout<<A[i][j]<<' ';
      }
      cout<<endl;
    }
  }

  return 0;
}
