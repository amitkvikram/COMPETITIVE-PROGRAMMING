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

int main(){
      int n;
      cin>>n;
      string s;
      cin>>s;

      int flag = 1;
      int x = 0, y =1;
      if(s[0] == 'R'){
            flag = 0;
            x = 1;
            y = 0;
      }

      int res = 0;

      for(int i =1; i<s.size() ; i++){
            if(s[i] == 'U'){
                  y++;
                  if(flag == 1 && x>y){
                        res++;
                        flag = 0;
                  }
                  else if(flag == 0 && y>x){
                        res++;
                        flag =1;
                  }
            }
            else{
                  x++;
                  if(flag == 1 && x>y){
                        //cout<<"Here"<<endl;
                        res++;
                        flag = 0;
                  }
                  else if(flag == 0 && y>x){
                      //cout<<"tHere"<<endl;
                        res++;
                        flag =1;
                  }
            }
            //cout<<x<<' '<<y<<' '<<res<<endl;
      }

      cout<<res<<endl;
      return 0;
}
