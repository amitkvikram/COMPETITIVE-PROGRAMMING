#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

string preprocess(string &str){
  char ch=str[0];
  string str1;
  str1.push_back(ch);
  for(int i =1; i<str.size();i++){
    if(str[i]!=ch){
      ch = str[i];
      str1.push_back(ch);
    }
  }

  return str1;
}

int lcs(string &str1, string &str2, int n, int m){
    vector< vector<int> > L(n+1, vector<int>(m+1));
    for(int i =0; i<n+1; i++){
        for(int j =0; j<m+1; j++){
            if(i == 0|| j==0){
                L[i][j]=0;
            }
            else if(str1[i-1]==str2[j-1]){
                L[i][j] = L[i-1][j-1]+1;
            }
            else{
                L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
    }
    return L[n][m];
}

int main(){
    int t;
    cin>>t;
    int n, m;
    while(t--){
        cin>>n>>m;
        string str1, str2;
        cin>>str1>>str2;
        string arr1 = preprocess(str1);
        n = arr1.size();
        string arr2 = preprocess(str2);
        m = arr2.size();
        int l = lcs(arr1, arr2, n, m);
        int res = n+m;
        res-= l;
        cout<<res<<endl;
    }
}
