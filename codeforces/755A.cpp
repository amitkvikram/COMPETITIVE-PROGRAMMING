#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

bool isPrime(int num){
      if(num == 2) return true;

      if(num%2==0){
            return false;
      }
      for(int i = 3; i<=sqrt(num); i+=2){
            if(num%i==0) return false;
      }

      return true;
}

int main(){
      int n;
      cin>>n;
      for(int i =1; i<1001; i++){
            if(!(isPrime(n*i+1))){
                  cout<<i<<endl;
                  return 0;
            }
      }
}
