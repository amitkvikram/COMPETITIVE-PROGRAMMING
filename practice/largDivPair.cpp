#include<bits/stdc++.h>
using namespace std;


set<int> s;
set<int>::iterator it;


bool isValid(int num){
    for(it = s.begin(); it != s.end();     it++){
        if(*it < num && num % (*it) != 0){
            return false;
        }
        else if(*it > num && (*it) % num != 0){
            return false;
        }
    }
    
    return true;
}

int getCnt(int i){
    if(i == 0){
        if(s.size() >= 2){
            return 1;        
        }
        else{
            return 0;
        }
    }
    
    int res =   -1;
    res = getCnt(i + 1);
    if(isValid(v[i])){
        s.insert(v[i]);
        res = max(res, getCnt(i + 1));
    } 
    
    return res;
}

int main(){
    
}
