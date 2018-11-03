#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<ll> vi;
ll MAX = 1e9+7;

class node{
public:
      ll cost;
      bool visited = false;
      list<ll> adj;
      ll id;
};

void fill_order(auto i, auto &v, auto &s){
      v[i].visited = true;
      for(auto j:v[i].adj){
            if(v[j].visited == false){
                  fill_order(j, v, s);
            }
      }
      s.push(i);
}

void topological_order(auto& v, auto &s){
      for(ll i =0; i<v.size(); i++){
            if(v[i].visited == false){
                  fill_order(i, v, s);
            }
      }
}

vector<node> get_transpose(auto& v){
      vector<node> v_t(v.size());
      for(ll i =0; i<v.size(); i++){
            for(auto j:v[i].adj){
                  v_t[j].adj.push_back(i);
            }
      }
      return v_t;
}

ll dfs(auto& v_t, auto& v, ll s, ll id, ll tmp, ll &cnt){
      //cout<<s<<','<<v[s].cost<<','<<tmp<<"  ";
      if(v[s].cost<tmp){
            cnt = 1;
            tmp = v[s].cost;
      }
      else if(v[s].cost == tmp){
            cnt++;
      }
      v[s].id = id;
      v_t[s].visited = true;
      for(auto i:v_t[s].adj){
            if(v_t[i].visited == false){
                  tmp = dfs(v_t, v, i, id, tmp, cnt);
            }
      }
      return tmp;
}

void get_component(auto& v_t, auto& v, auto& s, ll &cost, ll &count){
      ll id = 0;
      while(!s.empty()){
            ll tmp = s.top();
            s.pop();
            if(v_t[tmp].visited == false){
                  id++;
                  ll cnt = 0;
                  cost+=(dfs(v_t, v, tmp, id, 1e9+1, cnt));
                  count=((count%MAX) *(cnt%MAX))%MAX;
            }
      }
}

int main(){
      ll n;
      cin>>n;
      vector<node> v(n);
      for(auto& i:v){
            cin>>i.cost;
      }
      ll m, a, b;
      cin>>m;
      for(ll i =0; i<m; i++){
            cin>>a>>b;
            a--; b--;
            v[a].adj.push_back(b);
      }

      stack<ll> s;
      topological_order(v, s);
      vector<node> v_t = get_transpose(v);
      ll cost = 0, count = 1;
      get_component(v_t, v, s, cost, count);
      cout<<cost<<' '<<count%MAX<<endl;
}
