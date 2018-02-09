#include <bits/stdc++.h>
using namespace std;

typedef std::vector<int> vi;
typedef long long ll;

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  while(t--){
    ll x, n;
    cin>>x>>n;
    if(n<=3){
      cout<<"impossible";
    }
    else{
      ll sum = (n*(n+1)/2)-x;
      if(sum%2!=0){
        cout<<"impossible";
      }
      else{
        //cout<<"sum = "<<sum<<endl;
        sum=sum/2;
        if(sum<=x){
          for(int i =1; i<=n; i++) {
            if(i==x) cout<<'2';
            else if(i==sum-1 || i==1) cout<<'0';
            else cout<<'1';
          }
        }
        else{
            int flag = 0;
            ll sum1 = sum, n1 = n, num;
            if(sum<n) n1 = sum;
            for(int j = n1; j>=1; j--){
              sum1 = sum;
              for(int i =j; i>=1; i--){
                  if(i!=x){
                    if(sum1==0){
                      flag = 1;
                      num = j;
                      break;
                    }
                    else{
                      if(i<=sum1) sum1-=i;
                    }
                  }
              }
              if(flag == 1) break;
            }
            if(flag == 0) cout<<"impossible";
            else{
              sum1 = sum;
              vi v(n+1, 0);
              v[x] = 2;
              //cout<<"num = "<<num<<endl;
              for(int i = num; i>=1; i--){
                if(i!=x){
                  if(sum1==0){
                    break;
                  }
                  else{
                    if(i<=sum1){
                      sum1-=i;
                      v[i]=1;
                    }
                  }
                }
              }
              for(int i =1; i<=n; i++){
                cout<<v[i];
              }
            }
        }
      }
    }
    cout<<endl;
  }
  return 0;
}
