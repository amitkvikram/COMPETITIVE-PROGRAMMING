/* 
    Time Complexity: O(n*n) if done properly
*/

#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void printSubstr(string &s){
    for (int i = 0; i < s.size(); i++){
        for (int j = i; j < s.size(); j++){
            cout << s.substr(i, j - i + 1) << endl;
        }
    }
}

int main(){
    string s;
    cout << "Eneter String: ";  
    cin >> s;
    printSubstr(s);
}