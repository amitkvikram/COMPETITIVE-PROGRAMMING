#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<vector<ll>> vvi;
typedef vector<map<ll, pair<ll, int>>> vm;
#define ss second
#define ff first
const ll inf = LLONG_MAX;
int n;
ll total = LLONG_MAX;
map<ll, pair<ll, int>>::iterator it;

ll func1(int ind, vl &A, vl &B, vl &C, vm &mp, ll curr_sum, ll min_sum){
    // bool flag = false;
    it = mp[ind].find(min_sum);
    if(it != mp[ind].end()){
        return (it->ss).ff;
        // flag = true;
    }
    //if element can not be negative
    if(B[ind] == 1){
        // cout<<"1: "<<"ind = "<<ind<<" curr_sum = "<<curr_sum<<" min_sum = "<<min_sum<<"total = "<<total<<endl;
        if(min_sum + A[ind] <=0){
            // cout<<"returning from 1\n";
            mp[ind][min_sum] = pair<ll, int>{LLONG_MIN, 1};
            return LLONG_MIN;
        } 
        if(ind == n - 1){
            if(curr_sum + A[ind]<=total) total = curr_sum + A[ind];
            // cout<<"Last index in 1\n";
            mp[ind][min_sum] = pair<ll, int>{A[ind], 1};
            return A[ind];
        }
        ll temp1 = func1(ind + 1, A, B, C, mp, curr_sum + A[ind], min(A[ind], min_sum + A[ind]));
        // cout<<"1: "<<"ind = "<<ind<<" curr_sum = "<<curr_sum<<" min_sum = "<<min_sum<<"total = "<<total;
        // cout<<" temp1 = "<<temp1<<endl;
        if(temp1 == LLONG_MIN){
            mp[ind][min_sum] = pair<ll, int>{LLONG_MIN, 1};
            return temp1;
        } 
        if(curr_sum + temp1 + A[ind]<= total){
            total = curr_sum + A[ind] + temp1;
        }
        mp[ind][min_sum] = pair<ll, int>{temp1 + A[ind], 1};
        return temp1 + A[ind];
    }

    //if element can be negative
    else{
        // cout<<"2: "<<"ind = "<<ind<<" curr_sum = "<<curr_sum<<" min_sum = "<<min_sum<<"total = "<<total<<endl;
        if(min_sum + A[ind] <=0 ){
            mp[ind][min_sum] = {LLONG_MIN, 1};
            // cout<<"returning from 2\n";
            return LLONG_MIN;
        } 
        if(ind == n - 1){
            if(min_sum - A[ind] > 0){
                // cout<<"last in 2 ";
                // cout<<"min sum = "<<min_sum<<" A = "<<A[ind]<<"  ";
                if(curr_sum - A[ind] <= total){
                    // cout<<"Here error\n";
                    total = curr_sum - A[ind];
                    // C[ind] = -1;
                }
                mp[ind][min_sum] = pair<ll, int>{-A[ind], -1};
                return -A[ind];
            }
            else{
                if(curr_sum + A[ind] <= total){
                    total = curr_sum + A[ind];
                    // C[ind] = 1;
                }
                mp[ind][min_sum] = pair<ll, int>{A[ind], 1};
            }
            return A[ind];
        }
        ll temp1 = LLONG_MIN, temp2 = LLONG_MIN;
        if(min_sum + A[ind] > 0) temp1 = func1(ind + 1, A, B, C, mp, curr_sum + A[ind], min(A[ind], min_sum + A[ind]));   //Changing sign
        if(min_sum - A[ind] > 0 || ind == 0) temp2 = func1(ind + 1, A, B, C, mp, curr_sum - A[ind], min(-A[ind], min_sum - A[ind]));   //not changing sign
        // cout<<temp1<<' '<<temp2<<endl;
        if(temp1 != LLONG_MIN && temp2 == LLONG_MIN){
            // cout<<"Here "<<ind<<"temp1="<<temp1<<"temp2= "<<temp2<<" min_sum = "<<min_sum<<endl;
            if(temp1 + curr_sum + A[ind] <=total){
                total = temp1 + curr_sum + A[ind];
                // C[ind] = 1;
            }
            mp[ind][min_sum] = pair<ll, int>{temp1 + A[ind], 1};
            return temp1 + A[ind];
        }
        else if(temp2 != LLONG_MIN && temp1 == LLONG_MIN){
            // cout<<"Here "<<ind<<"temp1="<<temp1<<"temp2= "<<temp2<<" min_sum = "<<min_sum<<endl;
            if(temp2 + curr_sum - A[ind] <=total){
                total = temp2 + curr_sum - A[ind];
                // C[ind] = -1;
            }
            mp[ind][min_sum] = pair<ll, int>{temp2 - A[ind], -1};
            return temp2 - A[ind];
        }
        else if(temp1 != LLONG_MIN && temp2 != LLONG_MIN){
            // cout<<"Here "<<ind<<"temp1="<<temp1<<"temp2= "<<temp2<<" min_sum = "<<min_sum<<endl;
            if(curr_sum + A[ind] + temp1< curr_sum - A[ind] + temp2){
                if(temp1 + curr_sum + A[ind] <=total){
                    total = temp1 + curr_sum + A[ind];
                    // C[ind] = 1;
                }
                mp[ind][min_sum] = pair<ll, int>{temp1 + A[ind], 1};
                return temp1 + A[ind];
            }
            else{
                if(temp2 + curr_sum - A[ind] <=total){
                    total = temp2 + curr_sum - A[ind];
                    // C[ind] = -1;
                }
                mp[ind][min_sum] = pair<ll, int>{temp2 - A[ind], -1};
                return temp2 - A[ind];
            }
        }
        else{
            // cout<<"Here "<<ind<<"temp1= "<<temp1<<"temp2 = "<<temp2<<" min_sum = "<<min_sum<<endl;
            mp[ind][min_sum] = pair<ll, int>{LLONG_MIN, 1};
            return LLONG_MIN;
        }
    }
}

void path_creator(int ind, vl &A, vl &B, vl &C, vm &mp, ll curr_sum, ll min_sum){

}

int main()
{
    int t;
    cin >> t;
    vl A(100001);
    vl B(100001), C(100001);
    while(t--){
        cin >> n;
        vm mp(n);
        for (int i = 0; i <n; i++){
            cin >> A[i];
        }

        for(int i = 0; i<n; i++){
            B[i] = 1;
            C[i] = 1;
        }

        for(int i = 0; i<n; i++){
            if((i == 0 || A[i-1] > A[i]) && (i == n-1 || A[i + 1] > A[i])){
                B[i] = -1;
            }
        }


        // for(int i = 0;i<n; i++){
        //     cout<<B[i]*A[i]<<" ";
        // }

        //Calculate C[i]
        total = LLONG_MAX;
        func1(0, A, B, C, mp, 0, 0);

        // cout<<"TOTAL = "<<total<<endl;
        //Create C
        ll curr_sum = 0;
        for(int i = 0; i<n; i++){
            // cout<<curr_sum<<": ";
            if(B[i] == 1){
                curr_sum+= A[i];
                continue;
            }
            for(it = mp[i].begin(); it!=mp[i].end(); it++){
                if((it->ss).ff + curr_sum == total ){
                    // cout<<"got"<<i<<" Sum = "<<(it->ss).ff + curr_sum<<" ";
                    // cout<<(it->ss).ff<<" "<<(it->ss).ss<<endl;
                    C[i] = (it->ss).ss;
                    curr_sum+= (C[i] * A[i]);
                    break;
                }
            }
        }

        //Final print
        for(int i = 0; i<n; i++){
            if(C[i] == -1) cout<<-A[i]<<' ';
            else cout<<A[i]<<' ';
        }
        // cout<<endl<<"total = "<<total<<endl;
        cout<<endl;
    }
}