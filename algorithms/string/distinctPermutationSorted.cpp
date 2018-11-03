/* 
 1. Sort the given string in non-decreasing order and print it. 
    The first permutation is always the string sorted in non-decreasing order.

2. Start generating next higher permutation.
    Do it until next higher permutation is not possible.
    If we reach a permutation where all characters are sorted in non-increasing order, 
    then that permutation is the last permutation.

*/

#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

void printDistinctPermutationSorted(string &s){
    sort(s.begin(), s.end());
    do{
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
}

int main(){
    string s;
    cout << "Enter String: ";
    cin >> s;
    printDistinctPermutationSorted(s);
}