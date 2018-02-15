#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int main(){
      string str;
      cin>>str;
      string str2;
      for(int i =str.size()-1; i>=0; i--){
            str2.push_back(str[i]);
      }

      for(int i =0; i<str.size(); i++){
            str2.push_back(str[i]);

      }

      cout<<str2<<endl;
}
