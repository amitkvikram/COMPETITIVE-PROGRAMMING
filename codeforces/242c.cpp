#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int>> iii;
#define ff first
#define ss second 
const int inf = 1e9+7;
#define rep(i, a, b) for(int i = a; i < b; i++)


int row_num[] = {0, 0, -1, 1, -1, -1, 1, 1};
int col_num[] = {-1, 1, 0, 0, -1, 1, -1, 1};

// bool check(int i, int j){
//     return i >= 0 && j <=0 
// }

int main(){
    unordered_map<int, vector<ii>> mp;
    unordered_map<int, vector<ii>>::iterator it1;
    set<ii> vis;
    int x0, y0, x1, y1, n, r, a, b;
    cin>>x0>>y0>>x1>>y1>>n;

    while(n--){
        cin>>r>>a>>b;
        it1 = mp.find(r);
        if(it1 == mp.end()){
            vector<ii> temp;
            temp.push_back({a, b});
            mp.insert(make_pair(r, temp));
        }
        else{
            it1->second.push_back({a, b});
        }
    }

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {x0, y0}});
    vis.insert({x0, y0});
    vector<ii> temp;
    int res = -1;
    while(!q.empty()){
        iii curr = q.front();
        q.pop();

        if(curr.ss.ff == x1 && curr.ss.ss == y1){
            res = curr.ff;
            break;
        }

        rep(i, 0, 8){
            int x = curr.ss.ff + row_num[i];
            int y = curr.ss.ss + col_num[i];

            if(vis.find({x, y}) == vis.end()){
                it1 = mp.find(x);
                if(it1 != mp.end()){
                    temp = it1->second;    //copy: can be improved if reference is taken
                    for(int j = 0; j< temp.size(); j++){
                        if(y >= temp[j].ff && y <= temp[j].ss){
                            q.push({curr.ff + 1, {x, y}});
                            vis.insert({x, y});
                            break;
                        }
                    }
                }
            }
        }
    }

    cout<<res<<endl;

}