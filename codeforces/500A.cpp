#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Node{
public:
	int node;
	int visited = 0;
};

typedef std::vector<Node> vi;

int main() {
	int n, t;
	cin>>n>>t;
	vi v(n);
	for(int i =0 ; i<n-1; i++){
		cin>>v[i].node;
		v[i].node+=i;
	}
   v[n-1].node = -1;

	int temp, temp1;
	temp = 0;
	v[0].visited = 1;
	while(temp>-1){
		if(temp == t-1){
			cout<<"YES";
			return 0;
		}
		temp1 = temp;
		temp = -1;
		if(!(v[v[temp1].node].visited) && temp1!=n-1){
			temp = v[temp1].node;
			v[temp].visited = 1;
		}
	}

	cout<<"NO";

	return 0;
}
