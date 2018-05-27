    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    typedef std::vector<ll> vi;
    typedef pair<int,int> pi;
    #define ss second
    #define ff first
    // const int inf = INT_MAX;
    bool status = false;

    bool is_valid(int n, int m, int i, int j){
        return i<n && j<m && i>-1 && j>-1;
    }

    int adjacent_row[] = {-1, 1, 0, 0};
    int adjacent_col[] = {0, 0, -1, 1};

    int main(){
        int n, q;
        cin >> n >> q;
        vi v(n);
        cin >> v[0];
        for (int i = 1; i < n; i++)
        {
            cin >> v[i];
            v[i] += v[i - 1];
        }

        
        ll k, arrow = 0, curr_index = 0;
        for (int i = 0; i < q; i++)
        {
            cin >> k;
            arrow += k;

            curr_index = std::lower_bound(v.begin(), v.end(), arrow) - v.begin();

            

            if(curr_index<n){
                if(v[curr_index] == arrow){
                    curr_index++;
                }
            }

            if(curr_index>n-1){
                arrow = 0;
                curr_index = 0;
            }
            cout << n - curr_index << endl;
        }
    }