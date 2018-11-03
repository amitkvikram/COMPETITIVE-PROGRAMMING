#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef vector<vector<int>> vvi;

void dfs1(vvi &v, int s, vi &visited, stack<int> &st){
    visited[s] = true;
    for(int i =0; i<26; i++){
        if(v[s][i] == 1 && visited[i] == 0){
            dfs1(v, i, visited , st);
        }
    }
    st.push(s);
}

bool dfs(vvi &v, int s, vi &visited, vi &inStack){
      visited[s] = 1;
      inStack[s] = 1;
      for(int i =0; i<26; i++){
            if(v[s][i] == 1 && inStack[i]==1){
                  return true;
            }
            else if(visited[i] == 0 &&  v[s][i] == 1){
                  if(dfs(v, i, visited, inStack)) return true;
            }
      }

      inStack[s] = 0;
      return false;
}

bool detect_cycle(vvi &v, vi &visited){
      vi inStack(26, 0);
      for(int i =0; i<26; i++){
            if(visited[i] == false){
                  if(dfs(v, i, visited, inStack)) return true;
            }
      }

      return false;
}

void lexicographical(vvi &v){
      stack<int> st;
      vi visited(26, 0);
      if(detect_cycle(v, visited)){
            cout<<"Impossible\n";
            return;
      }

      for(int i =0; i<26; i++) visited[i]=0;
      for(int i =0; i<26; i++){
          if(visited[i] == 0){
              dfs1(v, i, visited, st);
          }
      }

      while(!st.empty()){
            cout<<(char)('a'+st.top());
            st.pop();
      }

      for(int i =0; i<26; i++){
            if(visited[i]== 0) cout<<'a'+i;
      }
      cout<<endl;
      return;
}

int main(){
      vvi v(26, vector<int>(26, 0));
      int n;
      cin>>n;
      string str1, str2;
      cin>>str1;
      while(--n){
            cin>>str2;
            int i = 0;
            while(i<str1.size() && i<str2.size()){
                  if(str1[i] != str2[i]){
                        v[str1[i] - 'a'][str2[i] - 'a'] = 1;
                        break;
                  }
                  i++;
            }
            if(i==str2.size() && str1.size()>str2.size()){
                  cout<<"Impossible"<<endl;
                  return 0;
            }
          str1 = str2;
      }

      lexicographical(v);
}
