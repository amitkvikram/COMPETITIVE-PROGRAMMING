#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<string , int> node;

typedef std::vector<list<node> > vi;

int hashVal(string& str, int &n1){
  int n =str.size(), h = 0;
  for(int  i =0; i<n; i++){
    h = (33*h + int(str[i]-'a'))%100001;
  }
  return h;
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  list<string> a;
  vi v(100001);
  string str;
  std::vector<int> hash;
  list<node>::iterator it;
  ll h;
  for(int i =0; i<n; i++){
    cin>>str;
    h = hashVal(str, n)%100001;
    int flag = 0;
    for(it = v[h].begin(); it!=v[h].end(); it++){
      if(((*it).first) == str){
        flag = 1;
        break;
      }
    }
    if(flag == 1){
      cout<<str+to_string(it->second)<<endl;
      it->second++;
    }
    else{
      cout<<"OK"<<endl;
      v[h].push_back(make_pair(str, 1));
    }
  }

  return 0;
}
