#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define ff first
#define ss second

int main(){
    int n, m;
    cin>>n>>m;

    int cnt = 0;
    while(n!=m){
        if(n > m){
            cnt+=n-m;
            m = n;
        }
        else if(m%2 == 0){
            m/=2;
            cnt++;
        }
        else{
            m+=1;
            m/=2;
            cnt+=2;
        }
    }

    cout<<cnt<<endl;

}