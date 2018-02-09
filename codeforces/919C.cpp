#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector< std::vector<char> > vvi;

int main(int argc, char const *argv[]) {
      int n, m, k, res = 0;
      cin>>n>>m>>k;
      std::vector< std::vector<char> > v(n, std::vector<char>(m));
      for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                  cin>>v[i][j];
            }
      }
      if(k==1){
          for(int i =0; i<n; i++){
              for(int j =0; j<m; j++){
                  if(v[i][j]=='.'){
                      res++;
                  }
              }
          }
          cout<<res<<endl;
          return 0;
      }

      char str1[k+1] ={'a'};
      for(int i =0; i<k; i++){
            str1[i] = '.';
      }

      const char *str = str1;
      // Along row
        //cout<<strlen(str1)<<' '<<str1<<endl;
      for(int i =0; i<n; i++){
            int it = std::search(v[i].begin(), v[i].end(), str, str + strlen(str)) - v[i].begin();
          //cout<<i<<' ';
            //cout<<it<<endl;
            while(it!=v[i].size()){
                //cout<<"yes"<<endl;
                  res++;
                  it = std::search(v[i].begin() + it+1, v[i].end(), str, str + strlen(str)) - v[i].begin();
                   //cout<<'a'<<it<<endl;
            }
      }

      ///////////////////////////////////////////////////////////////////////////////
      std::vector< std::vector<char> > v1(m, std::vector<char>(n));
      for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                  v1[i][j] = v[j][i];
            }
      }

      //Along Columns
      for(int i =0; i<m; i++){
            int it = std::search(v1[i].begin(), v1[i].end(), str, str + strlen(str)) - v1[i].begin();
          //cout<<it<<endl;
            while(it!=v1[i].size()){
                   // cout<<"yes"<<endl;
                  res++;
                  it = std::search(v1[i].begin() + it+1, v1[i].end(), str, str + strlen(str)) - v1[i].begin();
            }
      }
      cout<<res<<endl;
      return 0;
}
