#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int getMid(int left, int right){
    return left + (right - left)/2;
}

int MAX = 1000000;

vector<bool> isPrime(MAX + 1, true);

void sieveEratosthenes(){
    for(int p = 2; p*p<=MAX; p++){
        if(isPrime[p] == true){
            for(int i = p*2; i<=MAX; i+=p){
                isPrime[i] = false;
            }
        }
    }

    // for(int i = 2; i<=MAX; i++){
    //     if(isPrime[  i]){
    //         cout<<i<<" ";
    //     }
    // }
    // cout<<endl;
}

void updateValUtil(vi &segmentTree, vi &v, int left, int right, int nodeIndex, int ind){
    //If index not in range [left, right]
    if(ind < left || ind > right){
        return;
    }

    //If leaf node
    if(left == right){
        if(isPrime[v[left]]) segmentTree[nodeIndex] = 1;
        else segmentTree[nodeIndex] = 0;
        return;
    }

    int mid = getMid(left, right);
    updateValUtil(segmentTree, v, left, mid, 2*nodeIndex + 1, ind);
    updateValUtil(segmentTree, v, mid + 1, right, 2*nodeIndex + 2, ind);

    segmentTree[nodeIndex] = segmentTree[2*nodeIndex + 1] + segmentTree[2*nodeIndex + 2];
}

void updateVal(vi &segmentTree, vi &v, int ind, int val){
    if(ind < 0 || ind> v.size() - 1){
        return;
    }

    v[ind] = val;
    if(isPrime[v[ind]]){
        cout<<"Prime Number\n";
    }
    else cout<<"Not Prime\n";

    updateValUtil(segmentTree, v, 0, v.size() - 1, 0, ind); 
}

int getNumPrimeUtil(vi &segmentTree, int left, int right, int nodeIndex, int l, int r){
    //If no overlap
    if(left > r || right< l){
        return 0;
    }

    //If Complete Overlap
    if(left >= l && right<=r){
        return segmentTree[nodeIndex];
    }

    //If Partial Overlap
    int mid = getMid(left, right);
    return getNumPrimeUtil(segmentTree, left, mid, 2*nodeIndex + 1, l, r) +
            getNumPrimeUtil(segmentTree, mid + 1, right, 2*nodeIndex + 2, l, r);

}

int getNumPrime(vi &segmentTree, vi &v, int l, int r){
    if(l < 0 || r>v.size() - 1 || r<l){
        return 0;
    }

    return getNumPrimeUtil(segmentTree, 0, v.size() -1, 0, l, r);
}

void constructSegmentTreeUtil(vi &segmentTree, vi &v, int left, int right, int nodeIndex){
    cout<<"left: "<<left<<" right: "<<right<<" node: "<<nodeIndex<<endl;
    //If leaf Node
    if(left == right){
        if(isPrime[v[left]]) segmentTree[nodeIndex] = 1;
        else segmentTree[nodeIndex] = 0;
        return;
    }

    //else
    int mid = getMid(left, right);
    constructSegmentTreeUtil(segmentTree, v, left, mid, 2*nodeIndex + 1);
    constructSegmentTreeUtil(segmentTree, v, mid + 1, right, 2*nodeIndex + 2);

    segmentTree[nodeIndex] = segmentTree[2*nodeIndex + 1] + segmentTree[2*nodeIndex + 2];
}

void constructSegmentTree(vi &segmentTree, vi &v){
    int height = (int)ceil(log2(v.size()));
    int maxSize = 2*(int)pow(2, v.size()) - 1;

    segmentTree.resize(maxSize);

    constructSegmentTreeUtil(segmentTree, v, 0, v.size() - 1, 0);
}

int main(){
    int n;
    cin>>n;
    vi v(n);
    
    for(int i = 0; i < n; i++)  cin>>v[i];
    sieveEratosthenes();

    vector<int> segmentTree;
    constructSegmentTree(segmentTree, v);
    int t, q, l, r, val, ind;
    cin>>t;
    while(t--){
        cout<<"Enter Query: ";
        cin>>q;
        if(q == 1){
            cin>>ind>>val;
            updateVal(segmentTree, v, ind, val);
        }

        if(q == 2){
            cin>>l>>r;
            cout<<getNumPrime(segmentTree, v, l, r)<<endl;
        }
    }
}