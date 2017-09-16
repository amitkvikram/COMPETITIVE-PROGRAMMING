#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define REP(i,a,b) for(int i=a; i<b; i++)

int main() {
ll n;
int mod = 1000000007;
cin>>n;
vi v;
ll temp,sum=0;
REP(i, 0, n){          //n
  cin>>temp;
  v.push_back(temp);
}

sort(v.begin(), v.end());    //n*log(n)

temp =2;
int j=n-2;
REP(i, 1, n){
  sum=(sum+( (v[i]-v[j])%mod * (temp-1)))%mod;
  temp=(temp*2)%mod;
  j--;
}
std::cout << sum<< '\n';

return 0;
}
