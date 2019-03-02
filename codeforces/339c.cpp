#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ff first
#define ss second
typedef pair< int , int> ii;
#define rep(i, a, b) for(int i =a; i<b; i++)
#define pb push_back
typedef std::vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef vector<viii> viiii;
typedef vector<bool> vb;
typedef vector<vb> vbb;
typedef vector<vbb> vbbb;
typedef vector<vbbb> vbbbb;
const ll mod = 1000000007;               //1e9+7
const int inf = INT_MAX;

ll row_num[] = {-1, 0, 0, 1};
ll col_num[] = {0, -1, 1, 0};
char Move[] = {'U', 'L', 'R', 'D'};
int m;
bool cycle = false;
// vector<int> child(11, -1);
vector<int> temp;
//sum1 = {odd sum, even sum}
bool dfs(int s, vector<bool> &visited, vector<int> &v, ii sum1, int len){
    if(len >= m){
        temp.push_back(s);
        return true;
    }

    for(int i = 0; i< v.size(); i++){
        int ind = v[i];
        if(ind != s && sum1.ss + ind > sum1.ff){
            if(dfs(ind, visited, v, {sum1.ss + ind, sum1.ff}, len + 1)){
                temp.push_back(s);
                return true;
            }
        }
    }
    return false;
}

int main(){
    vector<int> v;
    char a;
    for(int i = 0; i < 10; i++){
        cin>>a;
        if(a == '1'){
            v.push_back(i + 1);
        }
    }

    // int m;
    cin>>m;

    vector<bool> visited(11, false);
    bool res = false;
    vector<int> temp1;
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < v.size(); i++){
        int ind = v[i];
        if(dfs(ind, visited, v, {ind, 0}, 1)){
            res = true;
            cout<<"YES\n";

            int curr = ind;
            reverse(temp.begin(), temp.end());
            rep(j, 0, m){
                cout<<temp[j]<<" ";
                // if(m%2 == 0){
                //     sum1+=temp[j];
                //     temp1.push_back(sum1);
                // }
                // else{
                //     sum2+=temp[j];
                //     temp1.push_back(sum2);
                // }
                // curr = child[curr];
            }

            // for(int i = 0; i < temp.size(); i++){
            //     cout<<temp1[i]<<" ";
            // }

            break;
        }
    }

    if(!res){
        cout<<"NO\n";
    }
}