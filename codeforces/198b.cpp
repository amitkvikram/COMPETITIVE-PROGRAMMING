#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
#define ff first
#define ss second

class pqNode{
    public:
    ii node;
    int waterLevel;

    pqNode(ii x,  int z){
        node = x;
        waterLevel = z;
    }
};

bool check(int x, int n){
    return x >=0 && x < n;
}

int main(){
    int n, k;
    cin>>n>>k;
    string wall[2];
    cin>>wall[0]>>wall[1];

    vector<vb> visited(n, vb(2, false));

    bool res = false;
    queue<pqNode> q;

    q.push(pqNode({0, 0}, 0));
    visited[0][0] = true;
    int x, y;


    while(!q.empty()){
        pqNode curr = q.front();
        q.pop();

        //one area up
        x = curr.node.ff + 1;
        y = curr.node.ss;

        if(x >= n){
            res = true;
            break;
        }

        if(check(x, n) && !visited[x][y] && curr.waterLevel < x && wall[y][x] != 'X'){
            visited[x][y] = true;
            q.push(pqNode({x, y}, curr.waterLevel + 1));
        }

        //one area down
        x = curr.node.ff - 1;
        y = curr.node.ss;

        if(check(x, n) && !visited[x][y] && curr.waterLevel < x && wall[y][x] != 'X'){
            visited[x][y] = true;
            q.push(pqNode({x, y}, curr.waterLevel + 1));
        }

        //jump to opposite wall
        x = curr.node.ff + k;
        y = 1 - curr.node.ss;
        if(x >= n){
            res = true;
            break;
        }

        if(check(x, n) && !visited[x][y] && curr.waterLevel< x && wall[y][x] != 'X'){
            visited[x][y] = true;
            q.push(pqNode({x, y}, curr.waterLevel + 1));
        }
    }

    if(res){
        cout<<"YES\n";
    }
    else cout<<"NO\n";
}