#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[]) {
  int n, m;
  cin>>n>>m;
  for(int i =0; i<n; i++){
    if(!(i%2)){
      for(int j =0; j<m; j++){
        cout<<'#';
      }
    }

    else{
      if(!((i/2)%2)){
        for(int i =0; i<m-1; i++){
          cout<<'.';
        }
        cout<<'#';
      }

      else{
        cout<<'#';
        for(int j=0; j<m-1; j++){
          cout<<'.';
        }
      }

    }
    cout<<endl;
  }
  return 0;
}
