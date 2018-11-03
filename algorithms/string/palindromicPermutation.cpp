#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

bool isPalin(string &s, vi &freq){
    for (int i = 0; i < s.size(); i++){
        freq[s[i] - 'a']++;
    }

    int odd = 0;
    for (int i = 0; i < 26; i++){
        if(freq[i]%2!=0)
            odd++;
    }
    int n = s.size();
    if ((n%2 == 1 && odd == 1) || (n%2 == 0 && odd == 0)){
        return true;
    }

    return false;
}

void palindromicPermutation(string &s){
    vi freq(26, 0);
    if (!isPalin(s, freq))
        return;

    string half;
    char oddC;
    int n = s.size();
    for (int i = 0; i < 26; i++)
    {
        if(freq[i]%2 == 1){
            oddC = (i + 'a');
        }
        else
            half += string(freq[i] / 2, i + 'a');
    }

    string palin;
    do
    {
        palin = half;
        if(n%2 == 1){
            palin += oddC;
        }

        string halfCopy = half;
        reverse(halfCopy.begin(), halfCopy.end());
         palin += halfCopy;
         cout << palin << endl;
    } while (next_permutation(half.begin(), half.end()));
}

int main(){
    string s;
    cout << "Enter String: ";
    cin >> s;
    palindromicPermutation(s);
}