#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

typedef std::vector<int> vi;

int main(){
	int n;
	cin>>n;
	vi arr(n+1, 0);

	int p;
	cin>>p;
	int temp;

	for(int i =0 ; i<p; i++){
		cin>>temp;
		if(arr[temp] == 0){
			n--;
			arr[temp] = 1;
		}
	}

	cin>>p;

	for(int i =0 ; i<p; i++){
		cin>>temp;
		if(arr[temp] == 0){
			n--;
			arr[temp] = 1;
		}
	}

	if(n == 0) cout<<"I become the guy.";
	else cout<<"Oh, my keyboard!";
}