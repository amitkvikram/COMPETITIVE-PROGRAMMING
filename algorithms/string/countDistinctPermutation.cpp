/*
   We can find the count without finding all permutation.
    Idea is to find all the characters that is getting repeated, i.e., 
    frequency of all the character. 
    Then, we divide the factorial of the length of string 
    by multiplication of factorial of frequency of characters.

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

void calcFactorial(vl &fact){
    fact[1] = 1;
    fact[0] = 1;
    for (int i = 2; i < fact.size(); i++)
    {
        fact[i] = fact[i - 1] * i;
    }
}

void calcFrequency(vl &freq, string &s){
    for (int i = 0; i < s.size(); i++){
        freq[s[i] - 'a']++;
    }
}

void countDistinctPermutation(string &s){
    int n = s.size();
    vl fact(n+1);
    calcFactorial(fact);
    vl freq(26, 0);
    calcFrequency(freq, s);

    int cnt = fact[n];
    for (int i = 0; i < 26; i++){
        cnt /= fact[freq[i]];
    }

    cout << cnt << endl;
}

int main(){
    string s;
    cout << "Enter String: ";
    cin >> s;
    countDistinctPermutation(s);
}