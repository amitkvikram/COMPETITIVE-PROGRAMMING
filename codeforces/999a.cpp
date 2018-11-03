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
    vi prsum(vi v){vi temp(v.size()); rep(i,0,v.size()){
        if(i>0) temp[i]=temp[i-1]+v[i];else temp[i] = v[i];}return temp;}

    const ll mod = 1000000007;  

    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    int main(){
        int n, m;
        cin >> n >> m;
        int r = n / m;

        vi v(n);
        vi cnt(m);
        rep(i, 0, n)
        {
            cin >> v[i];
            cnt[v[i] % m]++;
        }

        int curr;
        for (int i = m - 1; i >= 0; i--){
            if(cnt[i])<r){
                    curr = i;
                    break;
                }
        }

        for (int i = m - 1; i >= 0; i--)
        {
            if(cnt[i] > r){
                cnt[curr] += min(r - cnt[curr] , cnt[i] - r);
                if(cnt[curr] == r){
                    for (int j = curr - 1; j >= 0; j++){
                        if(cnt[j]<r){
                            curr = j;
                            break;
                        }
                    }
                }
            }
        }

        
    }
