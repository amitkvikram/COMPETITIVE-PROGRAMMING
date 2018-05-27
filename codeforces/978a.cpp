#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main(){
    int n;
    cin>>n;
    vi v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }

    vi v1(1001, 0);
    stack<int> tmp;
    for(int i = n - 1; i>=0; i--){
        if(v1[v[i]] == 0){
            tmp.push(v[i]);
            v1[v[i]] = 1;
        }
    }

    cout<<tmp.size()<<endl;
    while(!tmp.empty()){

        cout<<tmp.top()<<' ';
        tmp.pop();
    }
    cout<<endl;
}