#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vi v(n);
    int ham_d = 0,flag = 0, temp; //num stores number of unique integers in array A
                                   //num_2 stores the number of elements who occured twice
    vi freq(100001, 0);
    cin>>v[i];
    temp = v[i];
    for(int i =1; i<n; i++){
      cin>>v[i];
      if(v[i] == temp) flag = 1;
    }

    if(n==1){
      cout<<0<<endl<<v[0]<<endl;
    }

    else if(n<=3 && flag == 1){
      if(n==2) cout<<0<<endl<<v[0]<<' '<<v[1]<<endl;
      else{
        cout<<1<<endl;
        cout<<v[n-2]<<' '<<v[n-1]<<' '<<v[n-3]<<endl;
      }
    }

    else{
      if(flag == 0){
        cout<<n<<endl;
        cout<<v[n-1]<<' ';
        for(int i =0; i<n; i++){
          cout<<v[i]<<' ';
        }
        cout<<endl;
      }

      else{
        int ham_d1 = 0;
        //Calculation of ham_d for shifting by one space
          if(v[n-1] != v[0]) ham_d++;
          for(int i =0; i<n-1; i++){
            if(v[i]!=v[i+1]) ham_d++;
          }
        //Calcullation of ham_d1 for shifting by two namespace
          if(v[n-2] != v[0]) ham_d1++:
          if(v[n-1] != v[1]) ham_d1++;
          for(int i =0; i<n; i++){
            if(v[i]!=v[i+2]) ham_d1++;
          }

        //Printing Value
          if(ham_d>ham_d1){
            cout<<ham_d<<endl;
            cout<<v[n-1]<<' ';
            for(int i =0; i<n; i++){
              cout<<v[i]<<' ';
            }
            cout<<endl;
          }
        else{
          cout<<ham_d1<<endl;
          cout<<v[n-2]<<' '<<v[n-1]<<' ';
          for(int i=0; i<n; i++){
            cout<<v[i]<<' ';
          }
          cout<<endl;
        }
      }
    }

  }
  return 0;
}
