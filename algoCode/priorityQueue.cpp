#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;
#define PB push_back
#define rep(i,a,b) for(ll i=a; i<b; i++)
 
 
class Teacher{
  public:
    ll Di;
    ll Ti;
    ll Si;
 
};
 
bool compare(Teacher a, Teacher b){
   return a.Di<b.Di;
}
class LessThanByAge{
public:
  bool operator()(Teacher lhs, Teacher rhs){
    return lhs.Si < rhs.Si;
  }
};
 
 
int main(){
  ll t;
  cin>>t;
  while(t--){
    ll n, d;
    cin>>n>>d;
 
    vector<Teacher> trainer;
    Teacher temp;
 
    rep(i,0,n){
      cin>>temp.Di>>temp.Ti>>temp.Si;
      trainer.PB(temp);
    }
 
    sort(trainer.begin(), trainer.end(), compare);//sort in increasing orderon the basis of day
    std::priority_queue<Teacher,std::vector<Teacher>, LessThanByAge> pq;
    ll j=0;
    rep(i, 1, d+1){
        while(trainer[j].Di==i &&j<n){
          pq.push(trainer[j]);
          j++;
        }
 
        if(!pq.empty()){
          temp = pq.top();
           pq.pop();
          temp.Ti--;
         if(temp.Ti!=0)
          pq.push(temp);
      }
 
    }
    ll sum=0;
 
    while(!pq.empty()){
      temp= pq.top();
      pq.pop();
      sum+=temp.Ti*temp.Si;
    }
 
    cout<<sum<<endl;
  }
