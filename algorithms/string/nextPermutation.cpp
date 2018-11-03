/*
    1. Find the highest index i such that s[i] < s[i+1]. 
       If no such index exists, the permutation is the last permutation.
    2. Find the highest index j > i such that s[j] > s[i].
       Such a j must exist, since i+1 is such an index.
    3. Swap s[i] with s[j].
    4. Reverse the order of all of the elements after index i till the last element.
    5. Time Complexity: O(n)
    6. C++ function: next_permutation(s.begin(), s.end())
*/

#include<bits/stdc++.h>
using namespace std;

void swap(char *x, char *y){
    char temp = *x;
    *x = *y;
    *y = temp;
}

int bSearch(string &s, int l, int r, int key){
    int low = l, high = r, mid, index = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(s[mid] <= s[key]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
            if(index == -1 || s[index] >= s[mid])
                index = mid;
        }
    }

    return index;
}

string nextPermutation(string &s){
    int n = s.size(), ind1 = -1, ind2;
    for (int i = 0; i < n - 1; i++)     //O(n)
    {
        if(s[i] < s[i+1]){
            ind1 = i;
        }
    }

    if(ind1 == -1){
        return "";
    }
    //s.substr(ind1 + 1) is sorted in decreasing order
    ind2 = bSearch(s, ind1 + 1, n - 1, ind1);    //O(log(n))

    swap(&s[ind1], &s[ind2]);       
    reverse(s.begin() + ind1 + 1, s.end());     //After reverse: s.substr(ind1 + 1) is sorted in increasing order
    return s;
}

int main(){
    string s;
    cout << "Enter String: ";
    cin >> s;
    string s1 = s;
    next_permutation(s1.begin(), s1.end());
    cout << s1 << endl;
    string res = nextPermutation(s);
    if(res.empty()){
        cout << "Next Permutation doesn't exist";
    }
    else{
        cout << res << endl;
    }
}