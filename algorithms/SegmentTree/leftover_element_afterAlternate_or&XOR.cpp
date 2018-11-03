#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define sz size()

int getMid(int left, int right){
    return left+(right - left)/2;
}

void updateValUtil(vi &segmentTree, vi &v, int left, int right, int nodeIndex, int ind, int val, bool op){
    //if ind is out of range
    if(ind < left || ind > right){
        return;
    }

    //if leaf node
    if(left == right){
        segmentTree[nodeIndex] = val;
        return;
    }

    int mid = getMid(left, right);
    updateValUtil(segmentTree, v, left, mid, 2*nodeIndex + 1, ind, val, 1 - op);
    updateValUtil(segmentTree, v, mid + 1, right, 2*nodeIndex + 2, ind, val, 1 - op);
    if(op == true) segmentTree[nodeIndex] = segmentTree[2*nodeIndex + 1] | segmentTree[2*nodeIndex + 2];
    else segmentTree[nodeIndex] = segmentTree[2*nodeIndex + 1] ^ segmentTree[2*nodeIndex + 2];
}

void updateVal(vi &segmentTree, vi &v, int ind, int val, bool op){
    if(ind < 0 || ind > v.sz - 1){
        return;
    }

    v[ind] = val;

    updateValUtil(segmentTree, v, 0, v.sz - 1, 0, ind, val, op);
}

void constructSegmentTreeUtil(vi &segmentTree, vi &v, int left, int right, int nodeIndex, bool op){
    if(left == right){   //leaf node
        segmentTree[nodeIndex] = v[left];
        return;
    }

    int mid = getMid(left, right);
    constructSegmentTreeUtil(segmentTree, v, left, mid, 2*nodeIndex+1, 1-op);
    constructSegmentTreeUtil(segmentTree, v, mid + 1, right, 2*nodeIndex + 2, 1 - op);

    if(op == true){
        segmentTree[nodeIndex] = segmentTree[2*nodeIndex + 1] | segmentTree[2*nodeIndex + 2];
    }
    else{
        segmentTree[nodeIndex] = segmentTree[2*nodeIndex + 1] ^ segmentTree[2*nodeIndex + 2];
    }
}

void constructSegmentTree(vi &segmentTree, vi &v, bool &op){
    int height = (int)ceil(log2(v.sz));
    int maxSize = 2*(int)pow(2, height) - 1;
    segmentTree.resize(maxSize);

    op = true;         //true for OR and false for XOR
    if(height%2==0) op  = false;

    constructSegmentTreeUtil(segmentTree, v, 0, v.sz - 1, 0, op);
}

int main()
{
    int n;
    cin>>n;
    vi v(n);
    for(int i = 0; i<n; i++) cin>>v[i];

    vi segmentTree;
    bool op;
    constructSegmentTree(segmentTree, v, op);
    int t, q, ind, val, l, r;
    cin>>t;
    while(t--){
        cin>>ind>>val;
        updateVal(segmentTree, v, ind, val, op);
        cout<<segmentTree[0]<<endl;
    }
    return 0;
}
