#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef std::vector<int> vi;
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
    int n;
    cin >> n;
    string s;
    cin >> s;

    if(n == 1){
        cout << s << endl;
        return 0;
    }

    int num_1 = 0;

    for(auto ch:s){
        if(ch == '1')
            num_1++;
    }

    n = n - num_1;
    string res;

    res.push_back('1');

    for (int i = 0; i < n; i++){
        res.push_back('0');
    }
    cout << res << endl;
}