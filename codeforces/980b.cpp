#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

bool isvalid(int i, int j, int n, int m){
    return i >= 0 && j >= 0 && j < m && i < n;
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<vector<char>> v(4, vector<char>(n, '.'));

    if(k%2 == 0){
        cout << "YES\n";
        for (int j = 1; j < n - 1; j++)
        {
            for (int i = 1; i < 3; i++){
                if(k<=0)
                    break;
                v[i][j] = '#';
                k--;
            }
             if(k<=0)
                break;
        }
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < n; j++){
                cout << v[i][j];
            }
            cout << endl;
        }
    }

    else{
         cout << "YES\n";
        v[1][n / 2] = '#';
        k--;
        for (int j = 1; j < n / 2; j++)
        {
            for (int i = 1; i < 3; i++){
                if(k<=0)
                    break;
                v[i][j] = '#';
                v[i][n - 1 - j] = '#';
                k -= 2;
            }
             if(k<=0)
                break;
        }
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < n; j++){
                cout << v[i][j];
            }
            cout << endl;
        }
    }   
}