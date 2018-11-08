#include<bits/stdc++.h>
using namespace std;
class Temp{
    public:
        int a;
        int b;
    Temp(int x, int y){
        a = x;
        b = y;
    }
};

int main(){
    Temp obj1(2, 3);
    cout<< obj1.a<<" " << obj1.b<<endl;
}