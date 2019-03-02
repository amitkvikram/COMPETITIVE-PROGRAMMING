#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

// vi *** = {L, R, U, D, LU, LD, RU, RD};
vi rowNum = {0, 0, -1, 1, -1, 1, -1, 1};
vi colNum = {-1, 1, 0, 0, -1, -1, 1, 1};
vector<string> Moves = {"L", "R", "U", "D", "LU", "LD", "RU", "RD"};

int main(){
    string s, t;
    cin>>s>>t;
    cout<<max(abs(s[0] - t[0]), abs(s[1] - t[1]))<<endl;

    while(s!=t){
        string move = "";
        if(s[0] > t[0]){
            move += 'L';
            s[0] -= 1;
        }
        else if(s[0] < t[0]){
            move += 'R';
            s[0] += 1;
        }
        if(s[1] > t[1]){
            move += "D";
            s[1] -= 1;
        }
        else if(s[1] < t[1]){
            move += 'U';
            s[1] += 1;
        }

        cout<<move<<endl;
    }
}