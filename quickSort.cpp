#include<bits/stdc++.h>
using namespace std;
typedef std::vector<int> vi;

void partition(arr, int l, int r, int j){
      int pivot = arr[j];
      r--;
      while(l<r){
            if(arr[l]<arr[j] && arr[r]<=)
      }
}

void quickSort(int arr[], int l, int r) {
      if(l>=r) return;
      int j = partition(arr, int l, int r, int r);
      quickSort(arr, l, j-1);
      quickSort(arr, j+1, r);
}

int int main(int argc, char const *argv[]) {
      int n;
      cin>>n;
      vi v(n);
      for(int i =0;; i<n; i++){
            cin>>v[i];
      }

      quickSort(arr);
      cout<<"Sorted Array\n";
      for(int i =0; i<n; i++){
            cout<<v[i]<<' ';
      }

      cout<<endl;
      return 0;
}
