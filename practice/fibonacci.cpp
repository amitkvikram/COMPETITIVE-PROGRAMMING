#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main(){
    int a = 1, b = 1;
    int c = 0;
    int n;

    cin>>n; 
    for(int i = 1; i < n; i++){
        int c= a + b;
        a = b;
        b = c;
    }

    cout<<b<<endl;
    return 0;
}
