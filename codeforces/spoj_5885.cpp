#include<bits/stdc++.h>
using namespace std;

class Monsters{
    public:
     int Ci;
     int Ti;
     int Si;
};

bool compare(Monsters a, Monsters b){
      return a.Si>b.Si;
}

void collect(int time_i, int time_f, vector <Monsters> &monster, int *result, int n, int i){
      cout<<*result<<endl;
      if(i >= n){
            return ;
      }
      if(monster[i].Ti > time_f){
            cout<<"a"<<' ';
            int temp = min(time_f - time_i, monster[i].Ci);
            *result += temp * monster[i].Si;
            int Time_f = time_f - temp;
            collect(time_i , Time_f, monster, result, n, i+1);
      }
      else if(monster[i].Ti >time_i){
            cout<<"b"<<' ';
            int temp = min(monster[i].Ti - time_i, monster[i].Ci);
            *result += temp * monster[i].Si;
            int Time_f = monster[i].Ti - temp;
            collect(monster[i].Ti, time_f, monster, result, n, i+1);
            cout<<"I"<<' ';
            collect(time_i, Time_f, monster, result, n, i+1);
      }

}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        std::vector <Monsters> monster(n) ;
        for(int i=0;i<n;i++){
          cin>>monster[i].Ci>>monster[i].Ti>>monster[i].Si;
        }

        int time_i=0, time_f =1000001;
        int result=0;
        sort(monster.begin(), monster.end(), compare);
        collect(time_i, time_f, monster, &result, n, 0);
        cout<<result<<endl;
    }
    return 0;
}
