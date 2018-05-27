#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main(){
    int n;
    string s;
    cin>>n;
    cin>>s;
    int curr = 0;
    int res = 0;
    for(int i = 0; i<n; i++){
        if(s[i]!='x'){
            curr = 0;
        }

        else{
            if(curr == 2) res++;
            else curr++;
        }
    }
    cout<<res<<endl;
}