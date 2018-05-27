#include<bits/stdc++.h>
using namespace std;
#include <memory>
#include <string>
#include <cstdlib>
typedef long long ll;
typedef vector<int> vi;

class c1{
    public:
    int a;
    int b;
};

// const c1 &func1(){
//         c1 *ptr = new c1;
//         ptr->a = 10;
//         ptr->b = 20;
//         cout<<&(ptr->a)<<endl;
//         return *ptr;
// }

const c1 func1(){
    c1 obj;
    obj.a = 10;
    return obj;
}

int main(){
    vi v1(10, 1), v2(10, 2);
    vi v3(10);
    v3 = v1 + v2;
}