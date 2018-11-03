#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

typedef std::vector<int> vi;	

int main(){
	int n;
	cin>>n;

	vi v(n, 0);
	for(int i= 0; i<n; i++){
		cin>>v[i];
	}

	int maximum = v[max_element(v.begin(), v.end()) - v.begin()];
	int minimim = v[min_element(v.begin(), v.end()) - v.begin()];

	int pos1 = 0, pos2 = 0;

	for(int i =0; i<n; i++){
		if(v[i] == maximum){
			break;
		}
		pos1++;
	}

	for(int  i = n-1; i>=0; i--){
		if(v[i] == minimim) break;

		pos2++;
	}

	if(pos1>(n-1-pos2)) cout<<pos1+pos2-1;
	else cout<<pos1+pos2;
}