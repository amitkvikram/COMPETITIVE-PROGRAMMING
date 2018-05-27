#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int getMid(int left, int right){
    return left + (right - left)/2;
}

void updateValUtil(vi &segmentTree, vi &v, int left, int right, int nodeIndex, int ind, int val, bool op){
    //If Index out of range
    if(ind<left || ind>right){
        return;
    }

    //If Leaf Node
    if(left == right){
        segmentTree[nodeIndex] = v[left];
        return;
    }

    int mid = getMid(left, right);

    updateValUtil(segmentTree, v, left, mid, 2*nodeIndex + 1, ind, val, 1 - op);
    updateValUtil(segmentTree, v, mid + 1, right, 2*nodeIndex + 1, ind, val, 1 - op);

    if(op) segmentTree[nodeIndex] = segmentTree[2*nodeIndex + 1] ^ segmentTree[2*nodeIndex + 2];
    else segmentTree[nodeIndex] = segmentTree[2*nodeIndex + 1] | segmentTree[2*nodeIndex + 2];
}

void updateVal(vi &segmentTree, vi &v, int ind, int val, bool op){
    if(ind < 0 || ind>v.size() - 1){
        return;
    }
    v[ind] = val;
    updateValUtil(segmentTree, v, 0, v.size() - 1, 0, ind, val, op);
}

void constructSegmentTreeUtil(vi &segmentTree, vi &v, int left, int right, int nodeIndex, bool op){
    //If Leaf Node
    if(left == right){
        segmentTree[nodeIndex] = v[left];
        return;
    }

    int mid = getMid(left, right);
    constructSegmentTreeUtil(segmentTree, v, left, mid, 2*nodeIndex + 1, 1 - op);
    constructSegmentTreeUtil(segmentTree, v, mid + 1, right, 2*nodeIndex + 2, 1 - op);
    if(op) segmentTree[nodeIndex] = segmentTree[2*nodeIndex + 1] ^ segmentTree[2*nodeIndex + 2];
    else segmentTree[nodeIndex] = segmentTree[2*nodeIndex + 1] | segmentTree[2*nodeIndex + 2];
}

void constructSegmentTree(vi &segmentTree, vi &v, bool &op){
    int height = (int)ceil(log2(v.size()));
    int maxSize = 2*(int)pow(2, height) - 1;

    segmentTree.resize(maxSize);

    if(height%2!=0) op = false;
    else op = true;
    constructSegmentTreeUtil(segmentTree, v, 0, v.size() - 1, 0, op);   //false for OR operaton
}

int main(){
    int n;
    cin>>n;
    vi v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }

    vi segmentTree;
    bool op;
    constructSegmentTree(segmentTree, v, op);

    cout<<segmentTree[0]<<endl;
    updateVal(segmentTree, v, 0, 13, op);
    cout<<segmentTree[0]<<endl;
}