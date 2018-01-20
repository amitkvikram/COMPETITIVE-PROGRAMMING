#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<ll> v;

int main(int argc, char const *argv[]) {
  ll n;
  cin>>n;
  unordered_map<string, pair<int, int> > database;
  int max = 0, tmp, ind = n;
  string str, key;
  std::vector<pair<string, int> > v;
  unordered_map<string, pair<int, int> >::iterator itr;
  for(int i =0; i<n; i++){
    cin>>str>>tmp;
    v.push_back(make_pair(str, tmp));
    auto it = database.find(str);
    if(it!= database.end()) {
      it->second.first+=tmp;
      it->second.second = i;
    }
    else{
      database.insert(make_pair(str, make_pair(tmp, i)));
    }
  }

  for(auto it = database.begin(); it!=database.end(); it++){
    if(it->second.first >= max)  max = it->second.first;
  }

  for(auto it= database.begin(); it!= database.end(); it++){
    if(it->second.first == max){
      it->second.second = 1;
    }
    else it->second.second = 0;
  }

  //cout<<"MAX = "<<max<<endl;
  //cout<<"V_Size = "<<v.size()<<endl;

  unordered_map<string, pair<int, int> > database1;
  for(int i =0; i<n; i++){
    pair<string, int> temp = v[i];
    auto it2 = database.find(temp.first);
    if(it2->second.first == max){
      auto it = database1.find(temp.first);
      if(it!= database1.end()) {
        it->second.first+=temp.second;
        if(it->second.first >= max){
          itr = it;
          break;
        }
      }
      else{
        database1.insert(make_pair(temp.first, make_pair(temp.second, i)));
        it = database1.find(temp.first);
        if(it->second.first >= max){
          itr = it;
          break;
        }
      }
    }
  }

    cout<<itr->first;

  return 0;
}
