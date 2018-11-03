#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[]) {
      long long n;
      cin>>n;

      cout<<((n/2) * (1+n)) - ( (n + (n%2))/2 * (n));
      return 0;
}
