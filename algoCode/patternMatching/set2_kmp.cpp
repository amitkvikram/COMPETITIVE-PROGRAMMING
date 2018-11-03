#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
#define PB push_back

void kmp_search(string str1, string str2, vi &lps, vi &ind){
  int i =0, n= str1.size(), m = str2.size(), j= 0;
  while(i<n){
    if(str2[j]==str1[i]){
      i++; j++;
    }
    if(j==m){
      j = lps[j-1];
    }

    else if(i<n && str1[i]!=str2[j]){
      if(j>0) j = lps[j-1];
      else i++;
    }

  }
}

void prefix_table(vi &lsp, string str){
  int len =0;
  lps[0]=0;
  int i =1;
  while(i<m){
    if(str[i]==str[len]){
      lps[i]= len;
      i++;
      len++;
    }
    else{
      if(len!=0){

      }
    }
  }
}

int main(int argc, char const *argv[]) {
  string str1, str2;
  cin>>str1>>str2;
  vi lsp(str2.size()), ind;
  prefix_table(lsp, str2);
  for(int i =0; i<str2.size(); i++){
    cout<<lsp[i]<<' ';
  }
  cout<<endl;
  return 0;
}
