#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef pair< string,vi> pr;

int main(int argc, char const *argv[]) {

  int a, b, c, masha;
  cin>>a>>b>>c>>masha;

   if(c*2<masha || a<=masha || b<=masha ||c>2*masha) cout<<"-1";
   else{
     cout<<a*2<<endl<<b*2<<endl<<max(masha, c);
   }
  return 0;
}
