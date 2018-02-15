#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<list<int>> vl;
typedef std::vector<std::vector<int>> vvi;

int hash_value(string str){
      int h = 0;
      for(int i =0; i<str.size(); i++){
            h = ((str[i]-'0') + h*33)%1000;
      }
      return h%1000;
}

void longest_chain(vector<list<pair< string, list<string> > > > &v, string source){
      queue<pair<string, int>> q;
      q.push({source, 1});
      int res = 0;
      int count = 0;
      while(!q.empty()){
            count++;
            string tmp = q.front().first;
            int level = q.front().second;

            //cout<<tmp<<' '<<level<<' ';
            if(level>res) res = level;
            q.pop();
            int ind = hash_value(tmp);
           // cout<<ind<<endl;
            auto it = v[ind].begin();
            for(; it!=v[ind].end(); it++){
                  if((*it).first == tmp) break;
            }
            if(it!=v[ind].end()){
                for(auto it1 = (*it).second.begin(); it1!=(*it).second.end(); it1++){
                      q.push({(*it1), level+1});
                }
            }

      }

      cout<<res<<endl;
      return;
}

void lower(string &str1){
      transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
      return;
}

int main(){
      int n;
      cin>>n;
      vector<list<pair< string, list<string> > > > v(1001, list<pair< string, list<string> > >());
      string str1, str2, str3;
      cin>>str1>>str2>>str3;
      lower(str1);
      lower(str3);
      int ind = hash_value(str3);
      string source = str3;
      list<string> temp1;
      temp1.push_back(str1);
      v[ind].push_back({str3, temp1});
      for(int i =1; i<n; i++){
            cin>>str1>>str2>>str3;
            lower(str1);
            lower(str3);
            int ind = hash_value(str3);
            auto it = v[ind].begin();
            for(; it!=v[ind].end(); it++){
                  if((*it).first == str3){
                        break;
                  }
            }
            if(it!=v[ind].end()){
                  (*it).second.push_back(str1);
            }
            else{
                  list<string> temp;
                  temp.push_back(str1);
                  v[ind].push_back({str3, temp});
            }
      }

    longest_chain(v, source);
    return 0;
}
