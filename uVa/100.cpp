#include "bits/stdc++.h"

using namespace std;

void swap(int *i, int *j){
      int temp = *i;
      *i= *j;
      *j= temp;
}

int main(int argc, char const *argv[]) {
      int i, j;

       while (scanf ("%d %d", &i, &j) != EOF ){
             int max=0;
             int temp_i=i, temp_j=j;
             if(i>j) swap(&i, &j);
             for(int k = i; k<=j; k++){
                   int num=k, count=1;
                   while(num!=1){
                        count++;
                        if(num%2==0){
                              num= num/2;
                        }
                        else{
                              num= 3*num +1;
                        }
                  }
                  if(count>=max) max = count;
             }
             cout<<temp_i<<' '<<temp_j<<' '<<max<<endl;
       }
      return 0;
}
