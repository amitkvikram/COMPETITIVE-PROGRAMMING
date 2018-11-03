#include <bits/stdc++.h>
using namespace std;

typedef std::vector<int> vi;

vi preprocess(std::vector<int> &v, int block_size){
  vi block(100,0);
  for(int i =0; i<v.size(); i++){
    block[i/block_size]+=v[i];
  }

  return block;
}

void update(vi &v,  int block_size, int l, int r, vi &block){
  block[l/block_size]-=v[l];
  block[l/block_size]+=r;
  v[l] = r;
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  vi v(n);
  for(int i =0; i<n; i++){
    cin>>v[i];
  }
  int block_size = sqrt(n);

  std::vector<int> block = preprocess(v, block_size);

  int q;
  cin>>q;
  int t, l, r;
  while(q--){
    cin>>t>>l>>r;
    l--;
    if(t==1){
        update(v, block_size, l, r, block);
    }
    else{
      r--;
      int sum = 0;
      for(int i = l; i<=r; i++){
        if(i%block_size == 0 && r/block_size > i/block_size){
          sum+=block[i/block_size];
          i+=(block_size-1);
        }

        else sum+=v[i];
      }
      cout<<sum<<endl;
    }
  }
  return 0;
}
