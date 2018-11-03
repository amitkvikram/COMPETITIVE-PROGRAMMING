#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef pair< string,vi> pr;

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
    n--;
  char ch;
  string str;
  vi v(26, 0);
  int flag = 0;
  int count = 0, found = 0, num = 0;
  while(n--){
    cin>>ch>>str;
    if(ch == '!'){
      if(found == 1) num++;
      if(flag == 0){
        flag = 1;
        for(int i =0; i<str.size();i++){
          v[str[i]-'a'] = 1;
          count++;
        }
      }
      else{
        count = 0;
        for(int i = 0; i<str.size(); i++){
          if(v[str[i] - 'a'] == 1) {
            v[str[i] - 'a'] = 2;
            count++;
          }
        }
        for(int i =0; i<26; i++){
          if(v[i]!=2) v[i]=0;
          else v[i]=1;
        }
      }
    }
    else if(ch == '.'){
      for(int i =0; i<str.size(); i++){
        if(v[str[i]-'a'] == 1) count--;
        v[str[i] - 'a']=0;
      }
    }
    else{
        if(found == 1) num++;
    }
    if(count == 1) found = 1;
    //cout<<endl<<count<<endl;
  }

    cin>>ch>>str;

  cout<<num;
  return 0;
}
