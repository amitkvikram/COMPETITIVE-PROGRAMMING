#include<bits/stdc++.h>
using namespace std;

typedef std::vector<int> vi;
#define rep(i, a, b) for(int i = a; i<b; i++)
#define pb push_back
typedef pair<int, int> ii;
#define ss second
#define ff first
typedef long long ll;
#define all(a) (a.begin(), a.end())

class graphNode{
public:
      bool visited = false;
      int parent =-1;
      int size = 0;
      int size1;
      vector<pair<pair<int, int>, int>> subtree; //<index of vertes, wt for edge> size of subtree
};

bool mycompare(pair<pair<int, int>, int> &p1, pair<pair<int, int>, int> &p2){
      return p1.ss+p1.ff.ss<p2.ss+p2.ff.ss;
}

int dfs(vector<graphNode> &v, int s){
      v[s].visited =true;
      for(auto &it:v[s].subtree){
          int ind = it.ff.ff;
          int wt = it.ff.ss;
          if (v[ind].visited == true)
              continue;
          it.ss = dfs(v, ind); //size of subtree with root it.ff
          v[s].size += wt;                     //size of subtree with s as root
          v[s].size += it.ss;    //Size of subtree with s as root   
      }
      return v[s].size;
}

int find_dist(std::vector<graphNode> &v, int s, int flag){
      v[s].visited = true;
      int total = 0;
      int tmp_ind = 0;
      //   cout << s << ' ';
      rep(i, 0, v[s].subtree.size())
      {
          int ind = v[s].subtree[i].ff.ff;
          int wt = v[s].subtree[i].ff.ss;
          if(v[ind].visited == true)
              continue;
          v[ind].size1--;
          if (tmp_ind != v[s].size1 - 1)
          {
              cout << s << "->" << ind << endl;
              total += find_dist(v, ind, 1);
              total += 2 * wt;
          }
          else
          {
              if (flag == 1)
              {
                  cout << s << "-<" << ind << endl;
                  total += 2 * wt;
                  total += find_dist(v, ind, 1);
              }
              else
              {
                  total += find_dist(v, ind, 0);
                  total += wt;
              }
              
          }
          tmp_ind++;
      }
      cout <<s<<' '<< total << ' '<<flag<<' '<<v[s].size1<<endl;
      return total;
}

int main(){
      int n;
      cin>>n;
      int a, b , w;
      std::vector<graphNode> v(n);
      rep(i, 0, n-1){
            cin>>a>>b>>w;
            a--; b--;
            v[a].subtree.pb({{b, w},0});
            v[b].subtree.pb({{a, w},0});
      }

      dfs(v, 0);

      rep(i, 0, n){
          for (auto &it : v[i].subtree)
          {
              it.ss = v[it.ff.ff].size  ;
          }
      }


      rep(i, 0, n){
          v[i].visited = false;
          v[i].size1 = v[i].subtree.size();
          sort(v[i].subtree.begin(), v[i].subtree.end(), mycompare);
      }

        int res = find_dist(v, 0, 0);
        cout<<res<<endl;
}
