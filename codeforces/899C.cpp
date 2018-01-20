#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef pair< string,vi> pr;

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  vi v;
  if(n%2==0){
      for(int i=1; i<=n; i+=3){
        v.push_back(i);
        if(i%4==0) i-=2;
      }
      if(n%4==0){
        cout<<'0'<<endl;
        cout<<v.size()<<' ';
        for(int i=0; i<v.size(); i++){
          cout<<v[i]<<' ';
        }
      }

      else{
        cout<<'1'<<endl;
        cout<<v.size()<<' ';
        for(int i=0; i<v.size(); i++){
          cout<<v[i]<<' ';
        }
      }
  }

  else{
    int n1 = n;
    n--;
    int sum = n1(n1+1)/2;
    if(n%4==1){

    }

    else{
      cout<<n<<endl;
      v.push_back(n1);
      cout<<v.size()<<' ';
      for(int i=0; i<v.size(); i++){
        cout<<v[i]<<' ';
      }
    }
  }


  return 0;
}
