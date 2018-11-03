#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

typedef std::vector<int> vi;

int main(){
	int n, m;
	cin>>n>>m;
	n = min(n,m);
	if(n%2 == 0) cout<<"Malvika";
	else cout<<"Akshat";
	return 0;
}