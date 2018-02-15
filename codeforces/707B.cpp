#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

class dest{
    public:
      int ind;
      int wt;
};

void bfs(vi &storage, vector<list<dest>> &v, int n, int &rubel){
      for(int i = 0; i<n; i++){
            if(storage[i] == 1){
                  for(auto it = v[i].begin(); it!=v[i].end(); it++){
                        if(storage[(*it).ind]==0){
                              if(rubel == -1) rubel = (*it).wt;
                              else if((*it).wt < rubel){
                                    rubel = (*it).wt;
                              }
                        }
                  }
            }
      }
}

int main(){
      int n, m, k;
      cin>>n>>m>>k;
      vector<list<dest>> v(n);
      vi storage(n, 0);
      int i1, i2, l;
      for(int i = 0; i<m; i++){
            cin>>i1>>i2>>l;
            i1--; i2--;
            v[i1].push_back(dest{i2, l});
            v[i2].push_back({i1, l});
      }

      for(int i =0; i<k; i++){
            cin>>i1;
            i1--;
            storage[i1] = 1;
      }

      int rubel = -1;
      bfs(storage, v, n, rubel);
      cout<<rubel<<endl;
}
