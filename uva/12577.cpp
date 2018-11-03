#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int cnt = 0;
    while (true)
    {
        cin >> s;
        if(s == "*"){
            break;
        }
        if(s =="Hajj") cout <<"Case "<<cnt+1<< ": Hajj-e-Akbar\n";
        else
            cout <<"Case "<<cnt+1<< ": Hajj-e-Asghar\n";
        cnt += 1;
    }

    return 0;
}