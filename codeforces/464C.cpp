#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ff first
#define ss second
typedef pair< ll, ll > ii;
#define rep(i, a, b) for(ll i =a; i<b; i++)
#define pb push_back
typedef std::vector<ll> vi;
const int mod = 1000000007;

int main(){
      ll n;
      cin>>n;
      vi v(n);
      rep(i, 0, n){
            cin>>v[i];
      }
      ll s, f;
      cin>>s>>f;
      s--; f--;
      vi cum_sum(n, 0);
      cum_sum[0] = v[0];
      rep(i, 1, n){
            cum_sum[i] = cum_sum[i-1]+ v[i];
          //cout<<cum_sum[i]<<' ';
      }
      //cout<<endl;

      ll res = 0, cnt ,ind, tmp, tmp1;
      rep(i, 0, n){
            //cout<<"i:"<<i<<' ';
            cnt = 0;
            if(f>=i && s<=i){
                  //cout<<"Here"<<' ';
                  tmp = f - i - 1;
                  //cout<<tmp<<' ';
                  if(tmp>=0) cnt+=cum_sum[tmp];
                  tmp = n - i + s;
                  //cout<<tmp<<' ';
                  if(tmp<n && tmp>=0) cnt+=v[tmp];
                  if(tmp<n) cnt+=cum_sum[n-1] - cum_sum[tmp];
                  //cout<<cnt<<endl;
            }
            else if(f>=i && s>i){
                  //cout<<"Here1"<<endl;
                  tmp = s- i;
                  tmp1 = f - i -1;
                  if(tmp<n && tmp>=0) cnt+=v[tmp];
                  if(tmp<n && tmp>0 && tmp1<n && tmp>=0)cnt+=cum_sum[tmp1] - cum_sum[tmp];
                  //cnt-=cum_sum[tmp1];
            }

            else if(f<i){
                 // cout<<"Here2"<<endl;
                  tmp = s+n - i;
                  tmp1 = f+n - i;
                  if(tmp<n && tmp>=0) cnt+=v[tmp];
                  if(tmp1<n && tmp1>=0) cnt+=cum_sum[tmp1] - cum_sum[tmp];
                  if(tmp1<n && tmp1>=0) cnt-=v[tmp1];
            }

            if(cnt>res){
                  ind = i;
                  res = cnt;
            }
      }
      cout<<ind+1<<endl;

}
