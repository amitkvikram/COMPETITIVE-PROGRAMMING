#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;

int func1(int a, int b, int c, vi &v1){
    int r = b-a;
    int tmp = 0;
    bool check = true;
    vi v = v1;
    v[0] = a; v[1] = b; v[2] = c;
    for(int i = 3; i<v.size(); i++){
        if(v[i] == v[i-1]+r) continue;
        else if(v[i] == v[i-1]+r + 1){
            v[i] = v[i-1]+r;
            tmp+=1;
        }
        else if(v[i] == v[i-1]+r - 1){
            v[i] = v[i-1]+r;
            tmp+=1;
        }
        else{
            check = false ;
            break;
        }
    }
    // cout<<r<<' '<<tmp<<endl;
    if(check == false) return -1;
    else return tmp;
}

int main(){
    int n; 
    cin>>n;
    vi v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }

    if(n<3){
        cout<<0<<endl;
        return 0;
    }
    int a, b, c, res = INT_MAX, r, tmp;
    bool check;
    if((v[0] + v[2])%2 == 0){
        if(v[1] == (v[0] + v[2])/2){
            a = v[0];  b = v[1]; c = v[2];
            tmp = func1(a, b, c, v);
            if(tmp!=-1 && tmp<res) res = tmp;

            a = v[0]+1; b = v[1]+1; c = v[2] + 1;
            tmp = func1(a, b, c, v);
            if(tmp!=-1 && tmp + 3<res) res = tmp + 3 ;

            a = v[0]-1; b = v[1]-1; c = v[2] - 1;
            tmp = func1(a, b, c, v);
            if(tmp!=-1 && tmp + 3<res) res = tmp + 3;

            a = v[0]-1; b = v[1]; c = v[2] + 1;
            tmp = func1(a, b, c, v);
            if(tmp!=-1 && tmp + 2<res) res = tmp + 2;

            a = v[0]+1; b = v[1]; c = v[2] - 1;
            tmp = func1(a, b, c, v);
            if(tmp!=-1 && tmp + 2<res) res = tmp + 2;
        }
        else if(v[1] == (v[0] + v[2])/2 + 1){
            a = v[0], b= v[1] -1, c = v[2];
            tmp = func1(a, b, c, v);
            if(tmp!=-1 && tmp + 1<res) res = tmp + 1;

            a = v[0]-1; b = v[1] - 1; c = v[2] + 1;
            tmp = func1(a, b, c, v);
            if(tmp!=-1 && tmp + 3<res) res = tmp + 3;

            a = v[0]+1; b = v[1] - 1; c = v[2] - 1;
            tmp = func1(a, b, c, v);
            if(tmp!=-1 && tmp + 3<res) res = tmp + 3;

            a = v[0] + 1, b= v[1], c = v[2] + 1;
            tmp = func1(a, b, c, v) ;
            if(tmp!=-1 && tmp + 2<res) res = tmp + 2;

        }
        else if(v[1] == (v[0] + v[2])/2 - 1){
            a = v[0], b= v[1] + 1, c = v[2];
            tmp = func1(a, b, c, v);
            if(tmp!=-1 && tmp + 1<res) res = tmp + 1;

            a = v[0]+1; b = v[1] + 1; c = v[2] - 1;
            tmp = func1(a, b, c, v);
            if(tmp!=-1 && tmp + 3<res) res = tmp + 3;

            a = v[0]-1; b = v[1] + 1; c = v[2] + 1;
            tmp = func1(a, b, c, v);
            if(tmp!=-1 && tmp + 3<res) res = tmp + 3;

            a = v[0] - 1, b= v[1], c = v[2] - 1;
            tmp = func1(a, b, c, v);
            if(tmp!=-1 && tmp + 2<res) res = tmp + 2;
        }
        else if(v[1] == (v[0] + v[2])/2 - 2){
            a = v[0] - 1; b = v[1] + 1; c= v[2] -1;
            tmp = func1(a, b, c, v);
            if(tmp!=-1 && tmp + 3<res) res = tmp + 3;
        }
        else if(v[1] == (v[0] + v[2])/2 + 2){
            a = v[0] + 1; b = v[1] - 1; c= v[2] +1;
            tmp = func1(a, b, c, v);
            if(tmp!=-1 && tmp + 3<res) res = tmp + 3;
        }
    }
    //------------------------------------------------//
    else{
        if((v[0] + v[2]) /2  == v[1]){
            a = v[0] - 1; b  = v[1]; c = v[2];
            tmp = func1(a, b, c, v);
            if(tmp!=-1 && tmp + 1<res) res = tmp+1;

            a = v[0]; b= v[1]; c = v[2] - 1;
            tmp = func1(a, b, c, v);
            if(tmp!=-1 && tmp + 1<res) res = tmp+1;

            a = v[0] +1; b  = v[1] + 1; c = v[2];
            tmp = func1(a, b, c, v);
            if(tmp!=-1 && tmp + 2<res) res = tmp+2;

            a = v[0] ; b  = v[1] + 1; c = v[2]+1;
            tmp = func1(a, b, c, v);
            if(tmp!=-1 && tmp + 2<res) res = tmp+2;
        }
        else if((v[0] + v[2]) /2 +1 == v[1]){
            a = v[0]  + 1; b  = v[1] ; c = v[2];
            tmp = func1(a, b, c, v) ;
            if(tmp!=-1 && tmp + 1<res) res = tmp+1;

            a = v[0] ; b  = v[1]; c = v[2] + 1;
            tmp = func1(a, b, c, v);
            if(tmp!=-1 && tmp + 1<res) res = tmp+1;

            a = v[0] - 1; b  = v[1] - 1; c = v[2];
            tmp = func1(a, b, c, v);
            if(tmp!=-1 && tmp + 2<res) res = tmp+2;
            //BUG
            a = v[0]; b= v[1] - 1; c = v[2] - 1;
            tmp = func1(a, b, c, v);
            if(tmp!=-1 && tmp + 2<res) res = tmp+2;

        }
        else if((v[0] + v[2]) /2 -1 == v[1]){
            a = v[0] - 1; b  = v[1] + 1; c = v[2];
            tmp = func1(a, b, c, v) ;
            if(tmp!=-1 && tmp + 2<res) res = tmp+2;

            a = v[0] ; b  = v[1] + 1; c = v[2] - 1;
            tmp = func1(a, b, c, v);
            if(tmp!=-1 && tmp + 2<res) res = tmp + 2;
        }
        else if((v[0] + v[2]) /2  + 2 == v[1]){
            a = v[0] + 1; b  = v[1] - 1; c = v[2];
            tmp = func1(a, b, c, v);
            if(tmp!=-1 && tmp + 2<res) res = tmp + 2;

            a = v[0] ; b  = v[1] - 1; c = v[2] + 1;
            tmp = func1(a, b, c, v);
            if(tmp!=-1  && tmp + 2<res) res = tmp + 2;
        }
    }

    if(res == INT_MAX) cout<<"-1\n";
    else cout<<res<<endl;
}