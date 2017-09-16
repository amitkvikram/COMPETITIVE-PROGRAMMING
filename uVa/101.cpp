#include "bits/stdc++.h"

using namespace std;
typedef vector< vector<int> > vvi
#define push_back PB

vvi block;

move_onto(int a, int b){
      set_to_initial(int a, int b){
            while(!block[a].empty()){
                  int temp = block[a].pop();
                  block[temp].PB(temp);
            }
            while(!block[a].empty()){
                  int temp = block[a].pop();
                  block[temp].PB(temp);
            }
      }

      move_a_onto_b(int a, int b){
            block[b].PB(a);
            block[a].pop();
      }

      set_to_initial(a, b);
      move_a_onto_b(a,b);
}

move_over(int a, int b){
      
}


int main(){
      int n;
      cin>>n;
      string str1, str2;
      cin>>str1;
      int a, b;
      while(str1!="quit"){
            cin>>a>>str2>>b;

            if(str1=="move"){
                  if(str2=="onto"){
                        move_onto(aa, b);
                  }

                  else if(str2=="over"){
                        move_over();
                  }
            }

            else{
                  if(str2=="onto"){
                        pile_onto();
                  }

                  else if(str2 == "over"){
                        pile_over();
                  }
            }

      }
}
