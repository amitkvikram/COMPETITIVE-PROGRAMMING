#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<ll> v;

int main(int argc, char const *argv[]) {
  ll n;
  cin>>n;
  string str;
  unordered_map<string, int> database;
  for(int i =0; i<n; i++){
    cin>>str;
    auto it = database.find(str);
    if(it!= database.end()){
      cout<<str+to_string(it->second)<<endl;
      it->second++;
    }
    else{
      database.insert(make_pair(str, 1));
      cout<<"OK"<<endl;
    }
  }

  return 0;
}
