#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  string str1, str2;
  cin>>str1>>str2;
  if(str2>str1){
    cout<<"Pattern Not Found"<<endl;
    return 0;
  }

  int cnt = 0;  //counts the number of occurences of str2 in str1
  vi ind;       //stores starting indices of occurences

  int flag;
  for(int i =0; i<=str1.size()-str2.size(); i++){
    flag = 1;
    for(int j = 0; j<str2.size(); j++){
      if(str2[j]!=str1[i+j]){
         flag = 0;
         break;
      }
    }
    if(flag){
      ind.push_back(i);
    }
  }

  cout<<"No of occurences: "<<ind.size()<<endl;
  cout<<"Starting indices of occurences: "<<endl;
  for(int i =0; i<ind.size(); i++){
    cout<<ind[i]<<endl;
  }

  return 0;
}

/*
    Time Complexity: O(m*(n-m+1))
    where m is size of pattern and n is size of text.
*/
