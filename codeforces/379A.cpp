#include <iostream>
using namespace std;
int main() {
  int a, b;
  cin>>a>>b;
  int hr = 0, s = 0;
  while(a){
    hr++;
    if(hr%b == 0)  continue;
    a--;
  }

  cout<<hr;
  return 0;
}
