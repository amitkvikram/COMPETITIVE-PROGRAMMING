#include<bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;

bool is_valid(int n, int m, int i, int j){
    return i > -1 && j > -1 && i < n && j < m;
}

int main(){
    int n, m;       //n no of rows and m no of columns
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    int dest_row, dest_col;
    cin >> dest_row >> dest_col;

    for (int i = dest_row; i >= 0;i--){
        for (int j = dest_col; j >= 0; j--){
            int tmp = inf;
            //Down
            if(is_valid(n, m, i+1, j)){
                tmp = v[i + 1][j] + v[i][j];
            }
            //Right
            if(is_valid(n, m, j+1, i)){
                tmp = min(tmp, v[i][j + 1] + v[i][j]);
            }
            //Diagonal Down
            if(is_valid(n, m, i+1, j+1)){
                tmp = min(tmp, v[i + 1][j + 1] + v[i][j]);
            }

            if(tmp == inf)
                tmp = v[i][j];
            v[i][j] = tmp;
        }
    }

    cout << v[0][0] << endl;
}