#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<string> vi;

int main(int argc, char const *argv[]) {
  vi v;
  string line;
  while(std::getline(std::cin, line) ){
    v.push_back(line);
  }

  int n = v.size();
  for(int i =0;i<n; i++){
      int res=0, win_a = 0, win_b =0, match;

      //First 10 matches
      for(int j =0; j<10; j++){
        if(v[i][j]=='1'){
          if(j%2) win_b += 1;
          else win_a +=1;
        }

        if(win_a> (((9-j)/2)+(9-j)%2) + win_b){
          match = j+1;
          res =1;
          break;
        }

        else if(win_b> (9-j)/2 + win_a){
          match = j+1;
          res = 2;
          break;
        }
      }

      //If teams procedd to sudden death
      if(res == 0){
        for(int j = 10; j<20; j++){
            if(v[i][j] == '1'){
              if(j%2) win_b += 1;
              else win_a +=1;
            }

            if(j%2){
              if(win_a>win_b){
                res = 1;
                match = j+1;
                break;
              }
              else if(win_b>win_a){
                res = 2;
                match = j+1;
                break;
              }
            }
        }
      }

      if(res == 1){
        cout<<"TEAM-A "<<match<<endl;
      }
      else if(res == 2){
        cout<<"TEAM-B "<<match<<endl;
      }
      else cout<<"TIE"<<endl;
  }

  return 0;
}
