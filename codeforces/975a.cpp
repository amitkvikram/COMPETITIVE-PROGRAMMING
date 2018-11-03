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

    vector<vector<int>> v(0,vector<int>(26, 0));
    vector<int> tmp(26, 0);

    string str;
    int res = 0;
    bool match;
    while (n--)
    {
        match = false;
        cin >> str;
        std::fill(tmp.begin(), tmp.end(), 0);
        for (int i = 0; i < str.size(); i++)
        {
            tmp[str[i] - 'a'] = 1;
        }

        for (int i = 0; i < v.size(); i++){
            match = true;
            for (int j = 0; j < 26; j++){
                if(v[i][j]!=tmp[j])
                    match = false;
            }
            if(match == true)
                break;
        }

        if(match == false){
            v.push_back(tmp);
        }
    }

    cout << v.size() << endl;
}