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
vi prsum(vi v){
    vi temp(v.size()); rep(i,0,v.size()){if(i>0) temp[i]=temp[i-1]+v[i];else temp[i] = v[i];}return temp;}

const ll mod = 1000000007;  
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

int func1(vi v, ll n, ll sz){
    ll max2 = 0;
    for(int i = 0; i<26; i++){
        ll max1 = 0;
        int tmp = sz - v[i];
        if(n>tmp){
             if(n != 1) max1 = sz;
             else max1 = sz - 1;
        }
        else{
            max1 = v[i] + n;
        }
        if(max1>max2) max2 = max1;
    }

    for(int i = 32; i<58; i++){
        ll max1 = 0;
        int tmp = sz - v[i];
        if(n>tmp){
             if(n !=1) max1 = sz;
             else max1 = sz - 1;
        }
        else{
            max1 = v[i] + n;
        }
        if(max1>max2) max2 = max1;
    }
    return max2;
}
 
int main(){
    ll n;
    cin>>n;
    string s1 , s2, s3;
    cin>>s1>>s2>>s3;

    vi v1(300, 0), v2(300, 0), v3(300, 0);
    rep(i, 0, s1.size()){
        v1[s1[i] - 'A']++;
        v2[s2[i] - 'A']++;
        v3[s3[i] - 'A']++;
    }



    ll max1 = 0, max2 = 0, max3 = 0;
     ll sz = s1.size();
    max1 = func1(v1, n, sz);
    max2 = func1(v2, n, sz);
    max3 = func1(v3, n, sz);
    // rep(i, 0, 300){
    //     if(v1[i] > max1) max1 = v1[i];
    //     if(v2[i] > max2) max2 = v2[i];
    //     if(v3[i] > max3) max3 = v3[i];
    // }
    // //  cout<<max1<<" "<<max2<<" "<<max3<<endl;
    // if(n>sz){
    //     if((n -(sz - max1)) %2 !=0) max1 = s1.size() - 1;
    //     else max1 = sz;
    //     if((n - (sz - max2)) %2 !=0) max2 = s1.size() - 1;
    //     else max2 = sz;
    //     if((n - (sz - max3)) %2 !=0) max3 = s1.size() - 1;
    //     else max3 = sz;
    // }
    // else{
    //     if(n > sz - max1){
    //         if(n -(sz - max1)%2!=0) max1 = s1.size()-1;
    //         else max1 = sz;
    //     }
    //     else max1 = max1 + n;

    //     if(n > sz - max2){
    //         if(n -(sz - max2)%2!=0) max2 = s1.size()-1;
    //         else max2 = sz;
    //     }
    //     else max2 = max2 + n;

    //     if(n > sz - max3){
    //         if(n -(sz - max3)%2!=0) max3 = s1.size()-1;
    //         else max3 = sz;
    //     }
    //     else max3 = max3+n;
    // }
    // cout<<max1<<" "<<max2<<" "<<max3<<endl;
    ll tmp = max(max(max1, max2), max3);
    int cnt = 0;
    if(tmp == max1) cnt++;
    if(tmp == max2) cnt++;
    if(tmp == max3) cnt++;
    if(cnt>1) cout<<"Draw\n";
    else{
        if(tmp == max1){
            cout<<"Kuro\n";
        }
        else if(tmp == max2){
            cout<<"Shiro\n";
        }
        else cout<<"Katie\n";
    }
}