#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b) for(int i = a; i<b; i++)
#define all(v) v.begin(), v.end()

ll sum(vi v){ll init = 0; return accumulate(v.begin(), v.end(), init);}
ll sum(vii v, int check){
    ll init = 0;
    if(check == 1)
    return accumulate(v.begin(), v.end(), init, [](ll a, ii b){
        return a+b.ff;
    });
    else 
    return accumulate(v.begin(), v.end(), init, [](ll a, ii b){
        return a+b.ss;
    });
}
vi prsum(vi v){vi temp(v.size()); rep(i,0,v.size()){if(i>0) temp[i]=temp[i-1]+v[i];else temp[i] = v[i];}return temp;}

const ll mod = 1000000007;  

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

class node{
    public:
      vector<int> list;
      int parent;
      bool vis;
      int color;
      node()
      {
          parent = -1;
          vis = false;
          color = -1;
      }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<node> g(n);

    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        a--;
        b--;
        g[a].list.pb(b);
        g[b].list.pb(a);
    }

    stack<int> st;
    bool flag = true;
    vector<int> set1;
    vector<int> set2;
    for (int i = 0; i < n; i++){
        if(g[i].color == -1){
            st.push(i);
            g[i].color = 0;
            while (!st.empty())
            {
                int s = st.top();
                // cout << "s = " << s << endl;
                st.pop();
                g[s].vis = true;
                if (g[s].color == 0)
                    set1.push_back(s + 1);
                else
                    set2.push_back(s + 1);
                for (int i : g[s].list)
                {
                    if (g[i].color != -1)
                    {
                        if (g[s].color == g[i].color)
                        {
                            flag = false;
                            break;
                        }
                    }
                    else{
                        st.push(i);
                        g[i].color = 1 - g[s].color;
                    }
                }
            }

            if(!flag)
                break;
        }
    }

    if(!flag)
        cout << -1 << endl;

    else{
        cout << set1.size() << endl;
        for(int i:set1){
            cout << i << " ";
        }
        cout << endl;
        cout << set2.size() << endl;
        for(int i:set2){
            cout << i << " ";
        }
    }
}