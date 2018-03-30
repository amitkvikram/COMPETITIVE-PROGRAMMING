#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ff first
#define ss second
typedef pair< ll, ll > ii;
#define rep(i, a, b) for(ll i =a; i<b; i++)
#define pb push_back
typedef std::vector<ll> vi;
const int mod = 1000000007;               //1e9+7

int func1(string s[], int num, int cnt, int n, int k){
    if(cnt == k) return num;
      int t = 0, x;
      size_t pos, pos1;
      for(int i = 0; i<n; i++){
            pos = s[i].find("1");
            if(pos!=string::npos){
                  pos1 = s[i].find("1", pos+1);
                  if(pos1!=string::npos) x = pos1- pos;
                  else x = 1;
                   cout<<x<<' ';
                  s[i][pos] == '0';
                  x = func1(s, num+x, cnt+1, n, k);
                  s[i][pos] == '1';
                  if(x>t) t = x;
            }

            pos = s[i].find_last_of("1");
            if(pos!=string::npos){
                  pos1 = s[i].find_last_of("1", pos-1);
                  if(pos1!=string::npos) x = pos- pos1;
                  else x = 1;
                  s[i][pos] == '0';
                  x = func1(s, num+x, cnt+1, n, k);
                  s[i][pos] == '1';
                  if(x>t) t = x;
            }
      }
      cout<<t<<endl;
      return t;
}

int main(){
      ll n, m, k;
      cin>>n>>m>>k;
      string s[n];
      rep(i, 0, n){
            cin>>s[i];
      }
      int hr = 0;
    size_t pos, pos1;
      rep(i, 0, n){
          pos = s[i].find("1");
          pos1 = s[i].find_last_of("1");
          if(pos!=string::npos){
              if(pos1!=string::npos){
                  hr+=(pos1-pos+1);
              }
              else hr+=1;
          }
      }
     // cout<<hr<<"a"<<endl;
      int num = func1(s, 0, 0, n, k);
      //cout<<num<<endl;
      cout<<hr-num<<endl;
}
