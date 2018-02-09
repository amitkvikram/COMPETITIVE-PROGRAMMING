#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector< std::vector<int> > vvi;

int digit_sum(int n){
      int sum = 0;
      while(n){
            sum+=(n%10);
            n/=10;
      }
    return sum;
}

int main(int argc, char const *argv[]) {
      int k;
      cin>>k;
      vi v;
      for(int i =1; i<=20000000; i++){
            if(digit_sum(i) == 10){
                  v.push_back(i);
                  i+=8;
            }
      }
       //cout<<v.size()<<endl;
      cout<<v[k-1]<<endl;
      return 0;
}
