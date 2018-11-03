/*
    1. Time Complexity: O(n*n!)
*/

#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void swap(char *x, char *y){
    char temp = *x;
    *x = *y;
    *y = temp;
}

void printPerm(string &s, int l, int r){
    if(l == r){
        cout << s << endl;
    }
    else{
        for (int i = l; i <= r; i++){
            swap(&s[l], &s[i]);
            printPerm(s, l + 1, r);
            swap(&s[l], &s[i]);
        }
    }
}

void swap1(int *x, int *y){
    
}

int main(){

    string s;
    cout << "Enter String: ";
    cin >> s;
    printPerm(s, 0, s.size() - 1);
    char a = 'a', b = 'b';
    swap(a, b);
}