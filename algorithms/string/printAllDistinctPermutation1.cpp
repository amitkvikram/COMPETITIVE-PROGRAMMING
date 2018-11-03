#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void swap(char *x, char *y){
    char temp = *x;
    *x = *y;
    *y = temp;
}

void printAllDistinctPermutation1(string &s, int index){
    if(index == s.size() - 1){
        cout << s << endl;
        return;
    }

    unordered_set<char> mp;
    for (int i = index; i < s.size(); i++){
        if(mp.find(s[i]) == mp.end()){
            swap(&s[index], &s[i]);
            printAllDistinctPermutation1(s, index + 1);
            swap(&s[index], &s[i]);
            mp.insert(s[i]);
        }
    }
}

bool shouldSwap(string &s, int curr, int index){
    for (int i = curr; i < index; i++){
        if(s[index] == s[i]){
            return false;
        }
    }

    return true;
}

void printAllDistinctPermutation2(string &s, int index){
    if(index == s.size()){
        cout << s << endl;
        return;
    }

    for (int i = index; i < s.size(); i++){
        if(shouldSwap(s, index, i)){
            swap(&s[i], &s[index]);
            printAllDistinctPermutation2(s, index + 1);
            swap(&s[i], &s[index]);
        }
    }
}

int main(){
    string s;
    cout << "Enter String: ";
    cin >> s;
    printAllDistinctPermutation2(s, 0);
}