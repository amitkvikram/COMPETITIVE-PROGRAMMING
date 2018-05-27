#include<bits/stdc++.h>
using namespace std;

 string str1, str2;   //Sequences
 vector<vector<int>> arr;

 //Brute Force
//  int lcs(string &str1, string &str2, int i1, int j1)
//  {
//      int len = 0, tmp;
//      cout << i1 << ' ' << j1 << endl;
//      for (int i = i1; i < str1.size(); i++)
//      {
//          for (int j = j1; j < str2.size(); j++)
//          {
//              if (str1[i] == str2[j])
//              {
//                  tmp = lcs(str1, str2, i + 1, j + 1);
//                  if (1 + tmp > len)
//                      len = 1 + tmp;
//              }
//          }
//      }

//      return len;
// }

//Top Down
 int lcs(string &str1, string &str2, int i1, int j1)
 {
     if (i1 >= str1.size() || j1 >= str2.size())
         return 0;
     if(arr[i1][j1]!=-1)
         return arr[i1][j1];
     if (str1[i1] == str2[j1])
         arr[i1][j1] = 1 + lcs(str1, str2, i1 + 1, j1 + 1);
     else
     {
         arr[i1][j1] = max(lcs(str1, str2, i1, j1 + 1), lcs(str1, str2, i1 + 1, j1));
     }

     return arr[i1][j1];
}

//Bottom Up
int lcs(string &str1, string &str2){
    vector<vector<int>> v(str1.size(), vector<int> (str2.size(), 0));
    for (int i = 0; i < str1.size(); i++){
        for (int j = 0; j < str2.size(); j++){
            if(i == 0 && j == 0){
                if(str1[i] == str2[j]){
                    v[i][j] = 1;
                }
            }
            else if(i == 0){
                if(str1[i] == str2[j]){
                    v[i][j] = 1;
                }
                else
                    v[i][j] = v[0][j - 1];
            }

            else if(j == 0){
                if(str1[i] == str2[j]){
                    v[i][j] = 1;
                }
                else{
                    v[i][j] = v[i - 1][0];
                }
            }
            else if(str1[i] == str2[j]){
                v[i][j] = 1 + v[i - 1][j - 1];
            }
            else{
                v[i][j] = max(v[i - 1][j], v[i][j - 1]);
            }
        }
    }
    return v[str1.size() - 1][str2.size() - 1];
}

int main(){
    cin >> str1 >> str2;
    arr.resize(str1.size());
    for (int i = 0; i < str1.size(); i++){
        arr[i].resize(str2.size(), -1);
    }
    cout << lcs(str1, str2) << endl;
}