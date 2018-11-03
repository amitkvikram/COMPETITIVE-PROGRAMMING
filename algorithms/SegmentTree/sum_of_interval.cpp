#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define sz size()

int getMid(int left, int right){
    return left + (right - left)/2;
}

int numDiv[1000] = {0};

void calcDivisor(){
    for(int i = 1; i<1000; i++){
        for(int j = i; j<1000; j+=i){
            numDiv[i]++;
        }
    }
}

int getValUtil(vi &segmentTree, vi &lazy, vi &v, int left, int right, int nodeIndex, int l, int r){
    
}

int getVal(vi &segmentTree, vi &lazy, vi &v, int l, int r){
    if(l<0 || r>v.sz || r<l){
        return 0;
    }

    getValUtil(segmentTree, lazy, v, 0, v.sz - 1, 0, l, r);
}

void constructSegmentTreeUtil(vi &segmentTree, vi &lazy, vi &v, int left, int right, int nodeIndex){
    //If Leaf Node
    if(left == right){
        segmentTree[nodeIndex] = v[left];
        return;
    }

    int mid = getMid(left, right);
    constructSegmentTreeUtil(segmentTree, lazy, v, left, mid, 2*nodeIndex + 1);
    constructSegmentTreeUtil(segmentTree, lazy, v, mid + 1, right, 2*nodeIndex + 2);

    segmentTree[nodeIndex] = segmentTree[2*nodeIndex + 1] + segmentTree[2*nodeIndex + 2];
}

void constructSegmentTree(vi &segmentTree, vi &lazy, vi &v){
    int height = (int)ceil(log2(v.sz));
    int maxSize = 2*(int)pow(2, height) - 1;

    segmentTree.resize(maxSize);
    lazy.resize(maxSize, 0);

    constructSegmentTreeUtil(segmentTree, lazy, v, 0, v.sz - 1, 0);
}

int main(){
    int n;
    cin>>n;
    vi v(n);
    for(int i = 0; i<n; i++) cin>>v[i];

    vi segmentTree, lazy;

    constructSegmentTree(segmentTree, lazy, v);
    int t, q, l, r, val
}