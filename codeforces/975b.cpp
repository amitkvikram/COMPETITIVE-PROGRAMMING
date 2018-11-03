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
        vi v(14);
        for (int i = 0; i < 14; i++){
            cin >> v[i];
        }

        ll res = 0;

        for (int i = 0; i < 14; i++){
            vector<ll> tmp;
            tmp = v;
            ll num = v[i];
            tmp[i] = 0;
            for (int j = 0; j < 14; j++)
            {

                tmp[j] += (num / 14);
            }

            num = num % 14;

            for (int j = i + 1; j <= i + num; j++){
                tmp[j % 14] +=  1;
            }

            num = 0;
            for (int j = 0; j < 14; j++){
                // cout << tmp[j] << ' ';
                if (tmp[j] % 2 == 0)
                    num += tmp[j];
            }
            if (num > res)
                res = num;
        }

        cout << res << endl;
    }