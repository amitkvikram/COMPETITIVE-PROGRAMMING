#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int Min(int a, int b, int c){
  int tmp = b;
  if(a>b) tmp =a;
  if(c>tmp) tmp = c;
  return tmp;
}

int main(int argc, char const *argv[]) {
  int n, a, b , c;
  cin>>n>>a>>b>>c;

  vi v(n+1, -1);
  v[0] = 0;
  int tmp1 , tmp2, tmp3, tmp;
  for(int i = 1; i<n+1; i++){
    if(i-a>=0) tmp1 = v[i-a];
    else tmp1 = -1;

    if(i-b>=0)  tmp2 = v[i-b];
    else tmp2 = -1;

    if(i - c>=0) tmp3 = v[i-c];
    else tmp3 = -1;

    int tmp = Min(tmp1, tmp2, tmp3);
    if(tmp > v[i]) v[i] = tmp+1;
  }

  cout<<v[n];
  return 0;
}
