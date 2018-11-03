#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ff first
#define ss second
typedef pair< ll, ll > ii;
#define rep(i, a, b) for(ll i =a; i<b; i++)
#define pb push_back
typedef std::vector<ll> vi;
const ll mod = 1000000007;               //1e9+7s

int main(){
      string s[5] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};

      string str;
      cin>>str;
      int flag = 0;
      vi freq(5, 0);
      rep(i, 0, 5){
            size_t pos = str.find(s[i], 0);
            while(pos!=string::npos){
                  flag++;
                  pos = str.find(s[i], pos+1);
            }
      }

      if(flag == 1){
            cout<<"YES\n";
      }
      else cout<<"NO\n";
}
