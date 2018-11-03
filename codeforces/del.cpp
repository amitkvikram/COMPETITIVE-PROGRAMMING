#include<bits/stdc++.h>
using namespace std;
#include <memory>
#include <string>
#include <cstdlib>
typedef long long ll;
typedef vector<int> vi;

// class c1{
//     public:
//     int a;
//     int b;
//     void func1(const c1 obj2){
//         obj2.a = 20;
//         // this->a = 30;
//     }
// };

// const c1 &func1(){
//         c1 *ptr = new c1;
//         ptr->a = 10;
//         ptr->b = 20;
//         cout<<&(ptr->a)<<endl;
//         return *ptr;
// }

void operator+=(vector<int> &v1, vector<int> &v2){
    for (int i = 0; i < v1.size(); i++){
        v1[i] += v2[i];
    }
}

void operator<<(ostream &os, vector<int> &v1){
    for (int i = 0; i < v1.size(); i++){
        cout << v1[i] << " ";
    }
    cout << endl;
}

void operator-(vector<int> &v1){
    for (int i = 0; i<v1.size(); i++){
        v1[i] = -v1[i];
    }
}

int main(){
    vector<int> v(n);
    
}