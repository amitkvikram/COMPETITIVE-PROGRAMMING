#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector< std::vector<int> > vvi;

int main(int argc, char const *argv[]) {
      int t;
      cin>>t;
      while(t--){
            string s;
            cin>>s;
            vi v(26, 0);
            vector< std::vector<int> > index(26, vector<int>());
            for(int i =0; i<s.size(); i++){
                  v[s[i]-'a']++;
                  index[s[i]-'a'].push_back(i);
            }
            int flag = 0;
            for(int i =0; i<26; i++){
                  if(v[i]%2!=0) flag++;
                //cout<<v[i]<<' ';
            }
            if(flag>1){
                  cout<<"-1"<<endl;
            }
            else if(flag == 1 && s.size()%2==0){
                  cout<<"-1"<<endl;
            }
            else{
                  vi res(s.size());
                  string s1(s);
                  int ind1 = 0, ind2 = s.size()-1, tmp;
                  for(int i =0; i<26; i++){
                        if(v[i]%2!=0) {
                              s1[s.size()/2] = 'a'+i;
                              tmp = index[i].back();
                              index[i].pop_back();
                              res[s.size()/2] = tmp;
                              v[i]--;
                        }
                        int n = v[i];
                        while(n){
                              s1[ind1] = 'a'+i;
                              tmp = index[i].back();
                              index[i].pop_back();
                              res[ind1] = tmp;
                              ind1++;
                              tmp = index[i].back();
                              index[i].pop_back();
                              res[ind2] = tmp;
                              s1[ind2] = 'a'+i;
                              ind2--;
                              n-=2;
                        }
                  }
                  for(int i =0; i<res.size(); i++){
                        cout<<res[i]+1<<' ';
                  }
                  cout<<endl;
            }

      }
      return 0;
}
