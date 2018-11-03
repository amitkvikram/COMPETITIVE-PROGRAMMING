#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int main(){
    string str;
    long long L = (1e9 + 7);
    int n;
    cin>>n>>str;
    vi v(26,0);
    int max = 0;
    for(int i =0; i<n; i++){
        v[str[i]-'A']+=1;
        if(v[str[i]-'A']>=max) max = v[str[i]-'A'];
    }
    
    int count = 0;
    for(int i =0; i<26; i++){
        if(v[i]==max) count++;
    }
    long res = 1;
    count = count%L;
    for(int i = 0; i<n; i++){
        res = (((res)%L)*(count))%L;
    }
    cout<<res<<endl;
}
