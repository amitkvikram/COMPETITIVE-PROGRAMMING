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
      double R, x1, y1, x2, y2;
      cin>>R>>x1>>y1>>x2>>y2;
      double d = sqrt( pow(abs(x2-x1), 2) + pow(abs(y2-y1), 2) );

      if(d > R || (d-R < 0.0000000001 && d-R > -0.0000000001)){

            printf("%0.15lf %0.15lf %0.15lf\n", x1, y1, R);
            return 0;
      }
      double r = (d+R)/2, theta_s, theta_c;
      if(abs(x2 -x1) < 0.0000000001){
          theta_s = 1;
          theta_c = 0;
      }

      else if(abs(y2 - y1) < 0.0000000001){
          theta_s = 0;
          theta_c = 1;
      }

      else{
          double m = (y2 - y1) / (x2-x1);
          double m_2 = pow(m, 2);
          theta_s = sqrt(m_2 / (m_2 + 1));
          theta_c = 1 / sqrt(1+m_2);
      }

      //printf("%.15lf %.15lf\n",theta_c, theta_s);

      double x = x2 + r*(theta_c);
      if(x1 < x2 ) x = x2 - r*(theta_c);
      double y = y2+ r*(theta_s);
      if(y1 < y2 ) y = y2 - r*(theta_s) ;
      printf("%.15lf %.15lf %.15lf\n",x, y, r);
      return 0;
}
