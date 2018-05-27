#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int global_sum = INT_MIN, current_sum = 0;

    for (int i = 0; i < n; i++){
        current_sum += v[i];
        if(current_sum > global_sum)
            global_sum = current_sum;
        
        if(current_sum< 0)
            current_sum = 0;
    }

    cout << global_sum << endl;
}