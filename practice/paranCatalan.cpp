#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
int n;

int getCnt(int i, int lparan, int rparan){
    if( i >= n){
        return 1;
    }
    int tempCnt = 0;

    if(lparan - rparan > 0){
        tempCnt += getCnt(i + 1, lparan, rparan + 1);
    }

    if(lparan < n/2){
        tempCnt += getCnt(i + 1, lparan + 1, rparan);
    }

    return tempCnt;
}

int main(){
    cin>>n;
    n*=2;
    cout<<getCnt(0, 0, 0)<<endl;
}