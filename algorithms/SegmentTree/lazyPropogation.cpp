#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int getMid(int left, int right){
    return left+(right - left)/2;
}

void updateRangeValueUtil(vi &segmentTree, vi &lazy, vi &v, int left, int right, int nodeIndex, int l, int r, int val){
    //If node is pending to be updated
    if(lazy[nodeIndex]!=0){
        segmentTree[nodeIndex]+=((right - left + 1) * lazy[nodeIndex]);

        //if not leaf node
        if(left!=right){
            lazy[2*nodeIndex + 1]+=lazy[nodeIndex];
            lazy[2*nodeIndex + 2]+=lazy[nodeIndex];
        }
        lazy[nodeIndex] = 0;
    }

    //if no overlap
    if(left > r || right<l){
        return;
    }

    //If [left, right] is completly inside [l, r]
    if(left>=l && right<=r){
        segmentTree[nodeIndex]+=(right - left + 1)*val;
        if(left!=right){
            lazy[2*nodeIndex + 1]+=val;
            lazy[2*nodeIndex + 2]+=val;
        }
        
        return;
    }

    //if not completely in range
    int mid = getMid(left, right);
    updateRangeValueUtil(segmentTree, lazy, v, left, mid, 2*nodeIndex + 1, l, r, val);
    updateRangeValueUtil(segmentTree, lazy, v, mid + 1, right, 2*nodeIndex + 2, l, r, val);
    segmentTree[nodeIndex] = segmentTree[2*nodeIndex + 1] + segmentTree[2*nodeIndex + 2];
}

int getSumUtil(vi &segmentTree, vi &lazy, vi &v, int left, int right, int nodeIndex, int l, int r){
    if(lazy[nodeIndex]!=0){
        segmentTree[nodeIndex]+=(right - left + 1)*lazy[nodeIndex];
        if(left!=right){
            lazy[2*nodeIndex + 1]+=lazy[nodeIndex];
            lazy[2*nodeIndex + 2]+=lazy[nodeIndex];
        }
        lazy[nodeIndex] = 0;
    }

    //If no overlap
    if(left > r || right<l){
        return 0;
    }

    //If [left, right] is completely inside [l, r]
    if(left>=l && right<=r){
        return segmentTree[nodeIndex];
    }

    //if partial overlap
    int mid = getMid(left, right);

    return getSumUtil(segmentTree, lazy, v, left, mid, 2*nodeIndex + 1, l, r)+
                            getSumUtil(segmentTree, lazy, v, mid + 1, right, 2*nodeIndex + 2, l, r);
}

int getSum(vi &segmentTree, vi &lazy, vi &v, int l, int r){
    if(l<0 || r>v.size() - 1 || r<l){
        return 0;
    }

    return getSumUtil(segmentTree, lazy, v, 0, v.size() - 1, 0, l, r);
}

void updateRangeValue(vi &segmentTree, vi &lazy, vi &v, int l, int r, int val){
    if(l<0 || r>v.size() - 1|| r<l){
        return;
    }

    updateRangeValueUtil(segmentTree, lazy, v, 0, v.size() - 1, 0, l, r, val);
}   

void constructSegmentTreeUtil(vi &segmentTree, vi & v, int left, int right, int nodeIndex){
    //If leaf node
    if(left == right){
        segmentTree[nodeIndex] = v[left];
        return;
    }

    int mid = getMid(left, right);
    constructSegmentTreeUtil(segmentTree, v, left, mid, 2*nodeIndex + 1);
    constructSegmentTreeUtil(segmentTree, v, mid + 1, right, 2*nodeIndex + 2);

    segmentTree[nodeIndex] = segmentTree[2*nodeIndex + 1] + segmentTree[2*nodeIndex + 2];
}

void constructSegmentTree(vi &segmentTree, vi &lazy, vi &v){
    int height = (int)ceil(log2(v.size()));
    int maxSize = 2*(int)pow(2,  height)  - 1;

    segmentTree.resize(maxSize);
    lazy.resize(maxSize, 0);

    constructSegmentTreeUtil(segmentTree, v, 0, v.size() - 1, 0);
}

int main(){
    int n;
    cin>>n;
    vi v(n);

    for(int i = 0; i<n; i++) cin>>v[i];

    vi segmentTree, lazy;

    constructSegmentTree(segmentTree, lazy, v);
    int t, q, l, r, val;
    cin>>t;
    while(t--){
        cout<<"Enter Query: ";
        cin>>q;
        if(q == 1){
            cin>>l>>r>>val;
            updateRangeValue(segmentTree, lazy, v, l, r, val);
        }
        else{
            cin>>l>>r;
            cout<<getSum(segmentTree, lazy, v, l, r)<<endl;
        }
    }
}