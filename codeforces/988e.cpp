#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

void swap(char *x, char *y){
    char tmp = *x;
    *x = *y;
    *y = tmp;
}


int calc(string x, string y){
    int ind1 = -1, ind2 = -1;

    for (int i = x.size() - 1; i >= 0; i--){
        if(ind1 == -1 && x[i] == y[1])
            ind1 = i;
        else if(ind2 == -1 && x[i] == y[0])
            ind2 = i;
    }

    int mov = 0;
    if(ind1 == -1 || ind2 == -1)
        return INT_MAX;
    
    if(ind2 > ind1){
        ind2--;
    }
    //swap ind1
    for (int i = ind1; i <x.size() - 1; i++){
        swap(&x[i], &x[i + 1]);
        mov++;
    }

    //swap ind2
    for (int i = ind2; i <x.size()-2; i++){
        swap(&x[i], &x[i + 1]);
        mov++;
    }

    //check if zero
    for (int i = 0; i < x.size() - 2; i++){
        if(x[i]!='0'){
            for (int j = i; j - 1 >= 0; j--)
            {
                swap(&x[j], &x[j - 1]);
                mov++;
            }
            break;
        }
        if(i == x.size() - 3)
            return INT_MAX;
    }

    return mov;
}

int main(){
    string s;
    cin >> s;

    int res = min(calc(s, "00"), min(calc(s, "50"), min(calc(s, "25"), calc(s, "75"))));
    if(res == INT_MAX)
        cout << "-1\n";
    else
        cout << res << endl;
}