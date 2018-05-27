#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int getMid(int left, int right){
    return left + (right - left)/2;
}

int getMinInRangeHelper(vi &segmentTree, int left, int right, int nodeIndex, int l, int r){
    //If no overlap between [left, right] and [l, r]
    if(l > right || r < left){
        return INT_MAX;
    }

    //If [left, right] lies completely inside [l, r]
    if(left >=l && right <= r){
        return segmentTree[nodeIndex];
    }

    int mid = getMid(left, right);
    return min(getMinInRangeHelper(segmentTree, left, mid, 2*nodeIndex+1, l, r),
                getMinInRangeHelper(segmentTree, mid + 1, right, 2*nodeIndex + 2, l, r));
}

int getMinInRange(vi &segmentTree, int n, int l, int r){
    if(l<0 || r>n - 1 || r<l){
        cout<<"Invalid Index\n";
        return INT_MAX;
    }
    return getMinInRangeHelper(segmentTree, 0, n - 1, 0, l, r);
}

int constructSegmentTreeHelper(vi &v, vi &segmentTree, int left, int right, int nodeIndex){
    //If Leaf Node
    if(left == right){
        segmentTree[nodeIndex] = v[left];
        return v[left];
    }

    int mid = getMid(left, right);
    segmentTree[nodeIndex] = min(constructSegmentTreeHelper(v, segmentTree, left, mid, 2*nodeIndex + 1),
                                constructSegmentTreeHelper(v, segmentTree, mid +1  , right, 2*nodeIndex + 2));
    return segmentTree[nodeIndex];
}

vi & constructSegmentTree(vi &v){
    int height = (int)ceil(log2(v.size()));
    int maxSize = 2*(int)pow(2, height) - 1;

    vi *segmentTreePtr = new vector<int>(maxSize);

    constructSegmentTreeHelper(v, *segmentTreePtr, 0, v.size() - 1, 0);

    return *segmentTreePtr;
}

int main(){
    int n;
    cin>>n;
    vi v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }

    vi &segmentTree  = constructSegmentTree(v);
    int t, l, r;
    cin>>t;
    while(t--){
        cout<<"Enter Range: ";
        cin>>l>>r;
        cout<<getMinInRange(segmentTree, v.size(), l, r)<<endl;;
    }
}