#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int n;

int getCnt(int i){
    if(i >= n){
        return 1;
    }

    if(i == n - 1){
        return getCnt(i + 1);
    }

    return getCnt(i + 1) + getCnt(i + 2);
}

int main(){
    cin>>n;

    cout<<getCnt(0);
}