// Fake NP

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define REP(i,a,b) for(int i=a; i<=b; i++)

int main(int argc, char const *argv[]) {
  int l,r;
  cin>>l>>r;
  int a=2, max=0, temp=0;
  vi v(r+1, 0);

  int r1=sqrt(r);
 std::cout << r1 << '\n';
  REP(i, 1, r1){
    for(int j=l; j<=r; j++){
      if (j%i==0) {
         //std::cout << i <<' '<<j << '\n';
        v[i]=v[i]+1;
        //if(j!=i*i) v[j/i]=v[j/i]+1;
      }
    }
  }

   for(int i=2; i<=r; i++){
     //std::cout << v[i] << "A\n";
    if (v[i]>max) {
      max=v[i];
      a=i;
    }
   }


  std::cout << a << '\n';
  return 0;
}
