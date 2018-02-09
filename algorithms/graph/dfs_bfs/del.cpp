#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
      // std::vector<std::vector<int>> v{2,std::vector<int>()};
      // std::vector<int> v[2];
      std::vector<std::vector<int>> v(3);
      for(int i =0; i<2; i++){
            for(int j =0; j<3; j++){
                  v[i].push_back(j+i);
            }
      }

      for(int i =0; i<2; i++){
            for(int j =0; j<3; j++){
                  cout<<v[i].back()<<' ';
                  v[i].pop_back();
            }
            cout<<endl;
      }
      return 0;
}
