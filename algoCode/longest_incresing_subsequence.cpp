#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin >> n;
   vector<int> v(n);
   vector<int> subsequence(n, 1);
   int lis = 0;
   for (int i = 0; i < n; i++)
   {
       cin >> v[i];
       for (int j = 0; j < i; j++){
           if(1 + subsequence[j] > subsequence[i] && v[i] >=v[j]){
              subsequence[i] = subsequence[j] + 1;
           }
       }

       
       if(subsequence[i]>lis)
           lis = subsequence[i];
   }

   cout << lis << endl;
}
