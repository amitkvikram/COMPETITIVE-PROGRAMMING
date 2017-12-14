#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Dragon{
public:
  int strength;
  int bns;
};
typedef std::vector<Dragon> vi;

bool compare(Dragon a, Dragon b){
  return a.strength<b.strength;
}

int main(int argc, char const *argv[]) {
  int s, n;
  cin>>s>>n
  ;
  vi v(n);
  for(int i =0; i<n; i++){
    cin>>v[i].strength>>v[i].bns;
  }

  sort(v.begin(), v.end(), compare);

  for(int i =0; i<n; i++){
    if(s> v[i].strength){
      s+=v[i].bns;
    }

    else{
      cout<<"NO";
      return 0;
    }
  }

  cout<<"YES";
  return 0;
}
