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

class node{
    public:
    vector<int> adj;
    bool visited = false;
};

int main(){
    vector<int> currLevel, nextLevel;
    int startInd = 1;

    int n, a, b;
    cin>>n;

    vector<node> g(n);

    rep(i, 0, n - 1){
        cin>>a>>b;
        a--; b--;
        g[a].adj.push_back(b);
        g[b].adj.push_back(a);
    }
    vector<int> A(n);
    rep(i, 0, n){
        cin>>A[i];
        A[i]--;
    }

    if(A[0]!=1){
        cout<<"No\n";
        return 0;
    }

    nextLevel.push_back(A[0]);
    g[A[0]].visited = true;

    bool res = true;
    vector<int> temp;
    while(startInd < n){
        // cout<<"here\n";
        currLevel.swap(nextLevel);
        for(int i1 = 0; i1< currLevel.size(); i1++){
            int currInd = currLevel[i1], nextInd;
            // cout<<currInd<<endl;
            // currLevel.pop_back();
            unordered_set<int> mp;
            for(int i = 0; i< g[currInd].adj.size(); i++){
                nextInd = g[currInd].adj[i];
                if(g[nextInd].visited == false){
                    g[nextInd].visited = true;
                    temp.push_back(nextInd);
                    mp.insert(nextInd);
                }
            }

            for(int i = 0; i< temp.size(); i++){
                if(mp.find(A[startInd + i]) == mp.end()){
                    res = false;
                    break;
                }
                nextLevel.push_back(A[startInd + i]);
            }

            if(!res) break;
            startInd += temp.size();
            // while(!temp.empty()){
            //     nextLevel.push_back(temp.back());
            //     temp.pop_back();
            // }
            temp.clear();
        }
        currLevel.clear();
        if(!res) break;
    }

    if(!res) cout<<"No\n";
    else cout<<"Yes\n";
}