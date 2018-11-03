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
