#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<ll> vi;
#define PB push_back

void swap(ll *a, ll *b){
  ll tmp = *a;
  *a = *b;
  *b = tmp;
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  while(t--){
      int n;
      cin>>n;
      vi v(n);
      for(int i =0; i<n; i++){
       cin>>v[i];
      }
      int flag = 1, check, count = 0;
      if(n == 1) {
		cout<<0<<endl;
		return ;
	}
      if(n%2){
            //model1   d>b<a>c<e
            check = 0;
            int ind = n/2;
            while(ind){
                  if(!check){
                        if(v[ind]>v[ind+1] && v[ind-1]<v[ind]){
                              ind--;
                              continue;
                        }
                        else if(v[ind]>v[ind-1] && v[ind+1]<v[ind]){
                              swap(v[ind+1], v[ind-1]);
                              count++;
                        }
                        else{
                              flag = 0;
                              break;
                        }
                        check = !check;
                  }
                  else{
                        if(v[ind-1]>v[ind] && v[ind]<v[ind+1]){
                              ind--;
                              continue;
                        }
                        else if(v[ind+1]>v[ind] && v[ind-1]<v[ind]){
                              swap(v[ind+1], v[ind-1]);
                              count++;
                        }
                        else{
                              flag = 0;
                              break;
                        }
                        check = !check;
                  }
            }
                  //model2       d<b>a<c>e

            if(flag==0){
                  ind = n/2; flag = 1;
                  check = 0; count = 0;
                  while(ind){
                        if(!check){
                              if(v[ind]<v[ind+1] && v[ind-1]>v[ind]){
                                    ind--;
                                    continue;
                              }
                              else if(v[ind]<v[ind-1] && v[ind+1]>v[ind]){
                                    swap(v[ind+1], v[ind-1]);
                                    count++;
                              }
                              else{
                                    flag = 0;
                                    break;
                              }
                        }
                        else{
                              if(v[ind-1]<v[ind] && v[ind]>v[ind+1]){
                                    ind--;
                                    continue;
                              }
                              else if(v[ind+1]<v[ind] && v[ind-1]>v[ind]){
                                    swap(v[ind+1], v[ind-1]);
                                    count++;
                              }
                              else{
                                    flag = 0;
                                    break;
                              }
                        }
                        ind--;
                        check = !check;
                  }
            }
            if(flag == 1){
                  cout<<count<<endl;
            }
            else cout<<"-1"<<endl;
      }
      else{
            check = 0;
            int ind1 = n/2-1, ind2 = n/2,count1 = 0;
            //model1             c1<b1>a1<a2>b2<c2
            if(v[ind1]>v[ind2]) {
                  swap(v[ind1], v[ind2]);
                  count1++;
            }
            while(ind1){
                  if(!check){
                        if(v[ind1-1]>v[ind1] && v[ind2]>v[ind2+1]){
                              ind1--; ind2++;
                              continue;
                        }
                        else if(v[ind2+1]>v[ind1] && v[ind2]>v[ind1-1]){
                              // cout<<v[ind1-1]<<' '<<v[ind2+1]<<endl;
                              swap(v[ind2+1], v[ind1-1]);
                              count1++;
                        }
                        else{
                              flag = 0;
                              break;
                        }
                  }
                  else{
                        if(v[ind1-1]<v[ind1] && v[ind2]<v[ind2+1]){
                              ind1--; ind2++;
                              continue;
                        }
                        else if(v[ind2+1]<v[ind1] && v[ind2]<v[ind1-1]){
                              swap(v[ind2+1], v[ind1-1]);
                              count1++;
                        }
                        else{
                              flag = 0;
                              break;
                        }
                  }
                  ind1--; ind2++;
                  check = !check;
            }
            if(flag == 0) count1 = 1e5;
                  flag = 1;
                  check = 0; int count2 = 0;
                  ind1 = n/2-1, ind2 = n/2;
                  while(ind1){
                        if(check){
                              if(v[ind1-1]>v[ind1] && v[ind2]>v[ind2+1]){
                                    ind1--; ind2++;
                                    continue;
                              }
                              else if(v[ind2+1]>v[ind1] && v[ind2]>v[ind1-1]){
                                    swap(v[ind2+1], v[ind1-1]);
                                    count2++;
                              }
                              else{
                                    flag = 0;
                                    break;
                              }
                        }
                        else{
                              if(v[ind1-1]<v[ind1] && v[ind2]<v[ind2+1]){
                                    ind1--; ind2++;
                                    continue;
                              }
                              else if(v[ind2+1]<v[ind1] && v[ind2]<v[ind1-1]){
                                    swap(v[ind2+1], v[ind1-1]);
                                    count2++;
                              }
                              else{
                                    flag = 0;
                                    break;
                              }
                        }
                        ind1--; ind2++;
                        check = !check;
                  }
            if(flag == 1){
                  cout<<min(count1, count2)<<endl;
            }
            else cout<<"-1"<<endl;
      }
 }
  return 0;
}
