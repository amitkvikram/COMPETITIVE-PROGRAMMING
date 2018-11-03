#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

void bfs(vector<list<int>> &v, vi &in_deg, int n, int &res){
	queue<int> q;
	vi level(n, 1);
	vector<bool> visited(n, false);
	for(int i = 0; i<n; i++){
		if(in_deg[i] == 0){
			q.push(i);
			visited[i] = true;
		}
	}
	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		for(auto it = v[tmp].begin(); it!=v[tmp].end(); it++){
			if(visited[*it] == false){
				visited[*it] = true;
				level[*it] = level[tmp]+1;
				res = level[*it];
				q.push(*it);
			}
		}
	}
}

int main(){
	int n;
	cin>>n;
	vector<list<int>> v(n, list<int>());
	vi in_deg(n, 0);
	int tmp;
	for(int i = 0; i<n; i++){
		cin>>tmp;
		if(tmp!=-1){
			v[tmp-1].push_back(i);
			in_deg[i]++;
		}
	}

	int res;
	bfs(v, in_deg, n, res);
    cout<<res<<endl;
}
