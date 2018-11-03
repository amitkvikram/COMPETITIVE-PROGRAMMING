#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef std::vector<int> vi;
typedef pair<int,int> pi;
#define ss second
#define ff first
// const int inf = INT_MAX;
bool status = false;

bool is_valid(int n, int m, int i, int j){
      return i<n && j<m && i>-1 && j>-1;
}

int adjacent_row[] = {-1, 1, 0, 0};
int adjacent_col[] = {0, 0, -1, 1};

class cell{
public:

      int row;
      int col;
};

class queue_element{
    public:
      int wall;
      int cell;
      int water_level;
};


int main(){
      int n, k;
      cin>>n>>k;

      string wall[2];
      cin>>wall[0]>>wall[1];
      queue<queue_element> q;
      q.push({0, 0, 0});
      wall[0][0] = 'X';
      while (!q.empty())
      {
          queue_element tmp = q.front();
          q.pop();
        //   cout << tmp.cell << ' ' << tmp.wall << ' ' << tmp.water_level << endl;
          if (tmp.cell > n - 1)
          {
            //   cout << tmp.cell << ' ' << tmp.wall << endl;
              status = true;
              break;
          }

          //Climb up
          if(tmp.cell + 1 > n- 1 || (wall[tmp.wall][tmp.cell + 1]!='X')){
              q.push({tmp.wall, tmp.cell + 1, tmp.water_level + 1});
              if(tmp.cell + 1 <n)
                  wall[tmp.wall][tmp.cell + 1] = 'X';
          }

          //Climb Down
          if(tmp.cell - 1> - 1 && wall[tmp.wall][tmp.cell -1 ]!='X' && tmp.cell - 1 > tmp.water_level){
              q.push({tmp.wall, tmp.cell - 1, tmp.water_level + 1 });
              if(tmp.cell - 1 > - 1)
                  wall[tmp.wall][tmp.cell - 1] = 'X';
          }

          //Jump

          if(tmp.cell + k > n - 1 || wall[1 - tmp.wall][tmp.cell + k]!='X'){
              q.push({1 - tmp.wall, tmp.cell + k, tmp.water_level + 1});
              if(tmp.cell + k<n )
                  wall[1 - tmp.wall][tmp.cell + k] = 'X';
          }
      }

      if(status == true) cout<<"YES\n";
      else cout<<"NO\n";

      return 0;
}
