#include<bits/stdc++.h>
using namespace std;

/*Program to print all distinct permutation. It prints in lexicographic sorted order*/

typedef vector<int> vi;

void printAllDistinctPermutation(string &s){
    sort(s.begin(), s.end());
    do{
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
}

int main(){
    string s;
    cout << "Enter String: ";
    cin >> s;
    printAllDistinctPermutation(s);
}