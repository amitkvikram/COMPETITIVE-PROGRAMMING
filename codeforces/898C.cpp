#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<string> vi;
typedef pair< string,vi> pr;

int main() {
  int n;
  cin>>n;
  std::vector<pr> v;
  unordered_map< string , vi> database;

  string str, tmp;
  int m;
  for(int i=0; i<n; i++){
    cin>>str>>m;
    auto it = database.find(str);
    if(it==database.end()){
//cout<<str<<"EMPTY"<<endl;
      cin>>tmp;
      vi v = {tmp};
      database.insert(make_pair(str, v));
      m--;
    }
    for(int j =0; j<m; j++){
      cin>>tmp;
      it = database.find(str);
      if(it!=database.end()){
        int flag = 0;
        for(int i =0; i<it->second.size(); i++){
          //Checking any of already inserted phone no is suffix of current phone no.
           for(int l =0; l<tmp.size(); l++){
             if(tmp.substr(l) == it->second[i]){
               flag = 1;
               it->second[i]=tmp;
               break;
             }
           }

           //Checking current phone no. is end of already inserted number
           for(int l =0; l<it->second[i].size(); l++){
             if(it->second[i].substr(l) ==  tmp){
               flag = 1;
               break;
             }
           }
          if(flag == 1){
           // cout<<str<<' '<<tmp<<' '<<"FOUND"<<endl;
            break;
          }
        }
        if(flag == 0)   it->second.push_back(tmp);
      }

    }
  }

  cout<<database.size()<<endl;

  for(auto it = database.begin(); it!=database.end(); it++){
    cout<<it->first<<' ';
    cout<<it->second.size()<<' ';
    for(auto itr = it->second.begin(); itr!=it->second.end(); itr++){
      cout<<*itr<<' ';
    }
    cout<<endl;
  }


  return 0;
}
