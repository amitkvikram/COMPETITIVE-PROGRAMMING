#include<bits/stdc++.h>

using namespace std;

int main(){
    string str;
    cin>>str;
    int n = str.size();
    for(int i =1; i<str.size(); i++){
       if(str[i]==str[i-1]){
           str[i] = (str[i]+1-'a')%26 + 'a';
           if(i!=n-1 && str[i+1]==str[i]){
               str[i] = (str[i+1]+1-'a')%26+'a';
               
           }
       }
    }
    cout<<str<<endl;
}
