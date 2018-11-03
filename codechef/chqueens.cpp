#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b) for(int i = a; i<b; i++)
#define all(v) v.begin(), v.end()

ll sum(vi v){ll init = 0; return accumulate(v.begin(), v.end(), init);}
ll sum(vii v, int check){
    ll init = 0;
    if(check == 1)
    return accumulate(v.begin(), v.end(), init, [](ll a, ii b){
        return a+b.ff;
    });
    else 
    return accumulate(v.begin(), v.end(), init, [](ll a, ii b){
        return a+b.ss;
    });
}
vi prsum(vi v){vi temp(v.size()); rep(i,0,v.size()){if(i>0) temp[i]=temp[i-1]+v[i];else temp[i] = v[i];}return temp;}

const ll mod = 1000000007;  

/*Custom sort
     sort(v.begin(), v.end(), [](school s1, school s2){
        return s1.c<s2.c;       //this is ordering, if s1.c is less than s2.c then in sorted vector s1 will come before s2 = ascending order
         }); 
*/
    
/*Custom Lower_bound
    int ind = lower_bound(v.begin(), v.end(), 3, [](school s1, int num){
        return num > s1.c;            //num > s1.c should be false at the point at which lower_bound should break
    }) - v.begin();
*/

/*Priority Queue
  priority_queue<school, vector<school>, myCompare> pq;
  
  //myCompare for min Heap according to school.c
  class myCompare{
      public:
          int operator()(const school &s1, const school &s2){
              return s1.c > s2.c;
    }
  }

*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    int t;
    int n, m, x, y;
    vi A(101), B(101);

    cin>>t;
    while(t--){
        cin>>n>>m>>x>>y;
        int cnt = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int temp = 0;
                if(i == x and j == y){
                    continue;
                }
                //if i, j and x, y in same row
                if(i == x){
                    if(y > j){
                        temp+=(y - j - 1);
                    }
                    else{
                        temp+=y - 1;
                    }
                }
                else{
                    temp+=m - 1;
                }

                //if i, j and x, y in same col
                if(j == y){
                    if(x > i){
                        temp+=(n - x - 1);
                    }
                    else{
                        temp+= x - 1;
                    }
                }
                else{
                    temp+=n - 1;
                }

                //if i, j and x, y in diagonal
                if((x - i) == (y - j) || (x - i) == (j - i)){
                    if((x - i) == (y - j)){
                        //slope = 1
                        if(y < j){
                            temp+=(min(abs(n - x - 1), abs(0 - y)));
                        }
                        else{
                            temp+=(min(abs(x - 0), abs(y - m - 1)));
                        }
                    }
                    else{
                        //slope = -1
                        if(y > j){
                            temp+=(min(abs(n - x - 1), abs(m - y - 1)));
                        }
                        else{
                            temp+=(min(abs(x - 0), abs(y - 0)));
                        }
                    }
                }
                else{
                    temp+=(min(abs(i - 0), abs(j - 0)));
                    temp+=(min(abs(i - 0), abs(m - j - 1)));
                    temp+=(min(abs(n - i - 1), abs(j - 0)));
                    temp+=(min(abs(n - i - 1), abs(m - j - 1)));
                }
                cout<<temp<<endl;
                cnt+=(n*m - temp);
            }
        }
        cout<<cnt<<endl;
    }
}