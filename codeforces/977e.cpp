#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define ss second
#define ff first

class vertex{
    public:
      vector<int> adj;
      bool visited = false;
      int parent;
};

void dfs(vector<vertex> &v, int src, bool &check, int &cnt, int &dest, int &main_src){
    cnt++;
    v[src].visited = true;
    bool tmp_check = true, dest_check = false;
    for (int i : v[src].adj)
    {
        if(v[i].visited == true){
            if(src !=main_src){
                if(v[src].parent != i){
                    tmp_check = false;
                    if(i == main_src)
                        dest_check = true;
                }
            }

            else{
                if(i!=dest)
                    check = false;
            }
        }
        else{
            v[i].parent = src;
            dfs(v, i, check, cnt, dest, main_src);
        }
    }

    if(tmp_check == false){
        if(dest_check == false){
            // cout << "dest_check = false " << src << endl;
            check = false;
        }
            
        else{
            if(dest != -1){
                // cout << "two destination found " << src << endl;
                check = false;
            }
            else{
                // cout << "dest = " << src << endl;
                dest = src;
            }
                
        }
    }

    if(v[src].adj.size() == 1){
        // cout << "Heresize "<<src<<endl;
        check = false;
    }
    
}

int
main()
{
    int n, m;
    cin >> n >> m;
    vector<vertex> v(n);
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        a--;
        b--;
        v[a].adj.push_back(b);
        v[b].adj.push_back(a);
    }

    int res = 0,  cnt = 0;
    bool check = true;
    for (int i = 0; i < n; i++)
    {
        check = true;
        cnt = 0;
        if (v[i].visited == false)
        {
            // cout << i << ' ';
            int dest = -1;
            v[i].parent = -1;
            dfs(v, i, check, cnt, dest, i);
            // cout << check << ' ' << v[i].adj.size() << ' '<<cnt << endl;
            if (check && v[i].adj.size() == 2 && cnt >= 3)
                res++;
        }
    }

    cout << res << endl;
}