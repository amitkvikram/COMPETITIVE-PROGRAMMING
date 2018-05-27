#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define ff first
#define ss second

void binary_search1(vector<ii> &A, int orig_ind, int x, int &cnt_less, int &cnt_greater, int &less_needed, int &greater_needed){
    int low = 0, high = A.size() - 1, mid;
    while(low<=high){
        mid = (low + high) / 2;
        if(A[mid].ff == x)
            return;
        if(mid > orig_ind){
            greater_needed++;
            if (A[mid].ff < x)
                cnt_greater++;
            high = mid - 1;
        }
        else{
            less_needed++;
            if (A[mid].ff > x)
                cnt_less++;
            low = mid + 1;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;

        vector<ii> A(n);

        for (int i = 0; i < n; i++){
            cin >> A[i].ff;
            A[i].ss = i;
        }

        vector<ii> orig_A = A;

        sort(A.begin(), A.end(), [](ii a, ii b) {
            return a.ff < b.ff;
        });

        int x, cnt_less, cnt_greater, less_needed, greater_needed;
        for (int i = 0; i < q; i++){
            cin >> x;
            ii init = {x, 0};
            int ind = std::lower_bound(A.begin(), A.end(), ii{x, 0}) - A.begin();
            int orig_ind = A[ind].ss;
            cnt_less = 0;
            cnt_greater = 0;
            less_needed = 0;
            greater_needed = 0;
            binary_search1(orig_A, orig_ind, x, cnt_less, cnt_greater, less_needed, greater_needed);

            if(ind < less_needed || n - ind -1 < greater_needed){
                cout << "-1\n";
            }
            else{
                cout << max(cnt_less, cnt_greater)<<endl;
            }
        }
    }
}