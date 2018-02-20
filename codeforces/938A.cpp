#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<ll> vi;
ll MAX = 1e9+7;

bool check(char a){
      if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u' || a=='y') return true;
      else return false;
}

int main(){
      int n;
      cin>>n;
      string s;
      cin>>s;
      string s1;
            s1.push_back(s[0]);
      for(int i =1; i<s.size(); i++){
            if(check(s[i-1]) && check(s[i])){
                  continue;
            }
            else{
                  s1.push_back(s[i]);
            }
      }
      cout<<s1<<endl;
}
