#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
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

const int mod = 1000000007;  

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

bool isSorted(vi &v){
    for (int i = 0; i < (int)v.size() - 1; i++)
    {
        if(v[i+1] < v[i])
            return false;
    }

    return true;
}

int main(){
    int t;
    cin >> t;
    vi v(100001);
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        int ind = -1;
        for (int i = n - 1; i >= 1; i--)
        {
            if(v[i - 1] > v[i]){
                ind = i;
            }
        }

        if(ind == -1){
            cout << "YES\n";
        }
        else{
            vi temp(v.begin() + ind, v.begin() + n);
            for (int i = 0; i < ind; i++){
                temp.push_back(v[i]);
            }
            if (isSorted(temp))
            {
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
}
