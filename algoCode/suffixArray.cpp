#include<bits/stdc++.h>

using namespace std;
string str2 = "banana";

bool compare(int &a, int &b){
    return (str2.compare(a, string::npos, str2, b, string::npos)<0);
    //return b>a;
}

void print(int j){
    for(int i =j; i<str2.size();i++){
        cout<<str2[i];
    }
}

int main(){
    cout<<bool(-13)<<' '<<bool(1)<<' '<<bool(0)<<endl;
    int n = str2.size();
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        v[i] = i;
    }

    sort(v.begin(), v.end(), compare);
    for(int i =0; i<n; i++){
        cout<<v[i]<<' ';
        print(v[i]);
        cout<<endl;
    }
}
