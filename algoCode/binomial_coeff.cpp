#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int> vi;

int arr[100][100];

int top_down(int n, int k){
    // cout << n << ' ' << k << endl;
    if (k > n)
        return 0;
    if (k == 0)
        return 1;
    if(arr[n][k] == -1){
        // cout << "Calling\n";
        arr[n][k] = top_down(n - 1, k - 1) + top_down(n - 1, k);
    }
    return arr[n][k];
}

int bottom_up(int n, int k){
    int C[n + 1][k + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, k); j++){
            if(j == 0 || j == i)
                C[i][j] = 1;
            
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return C[n][k];
}

int main(){
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            arr[i][j] = -1;
        }
    }
        cout << top_down(n, k)<<endl;
        cout << bottom_up(n, k)<<endl;
}