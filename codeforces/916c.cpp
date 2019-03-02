#include<bits/stdc++.h> 
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef long long ll;
typedef pair<int, int> ii;

#define ff first
#define ss second

bool isPrime(int n){
    if(n == 1){
        return false;
    }

    if(n!=2 && n%2 == 0){
        return false;
    }

    for(int i = 3; i <= sqrt(n); i+=2){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int getPrime(int i){
    while(1){
        i+=1;
        if(isPrime(i)){
            return i;
        }
    }
}
int main(){
    int n, m;
    cin>>n>>m;
    int sp = getPrime(n - 2);
    cout<<sp<<' '<<sp<<endl;

    for(int i = 0; i<n-2; i++){
        cout<<i+1<<" "<<i+2<<" "<<1<<endl;
    }

    cout<<n-1<<" "<<n<<" "<<sp - n + 2<<endl;

    sp++;

    m-=(n-1);
    int node1 = 1, node2 = 3;
    while(m--){

        if(node2 > n){
            node1+=1;
            node2 = node1 + 2;
            m+=1;
            continue;
        }

        cout<<node1<<" "<<node2<<" "<<sp<<endl;
        node2++;
    }
}