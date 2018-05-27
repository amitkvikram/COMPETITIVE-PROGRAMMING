#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;



int getMid(int left, int right){
    return left + (right - left)/2;
}

int getBlackUtil(vi &segmentTree, vi &lazy, vi &v, int left, int right, int nodeIndex, int l, int r){
    cout<<"Get black util: "<<left<<' '<<right<<' '<<l<<' '<<r<<endl;
    if(lazy[nodeIndex]!=0){
        segmentTree[nodeIndex] = right - left + 1 - segmentTree[nodeIndex];
        if(left!=right){
            lazy[2*nodeIndex + 1] = 1 - lazy[2*nodeIndex + 1];
            lazy[2* nodeIndex + 2] = 1 - lazy[2*nodeIndex + 2];
        }

        lazy[nodeIndex] = 0;
    }

    //If out of range
    if(left > r || right<l){
        return 0;
    }

    //if [left, right] is completely inside [l, r]
    if(left>=l && right<=r){
        cout<<"Completely Inside"<<left<<' '<<right<<endl;
        return segmentTree[nodeIndex];
    }

    //If partial overlap
    int mid = getMid(left, right);
    return getBlackUtil(segmentTree, lazy, v, left, mid, 2*nodeIndex + 1, l, r) +
        getBlackUtil(segmentTree, lazy, v, mid + 1, right, 2*nodeIndex + 2 , l, r);
}

void updateRangeValueUtil(vi &segmentTree, vi &lazy, vi &v, int left, int right, int nodeIndex, int l, int r){
    if(lazy[nodeIndex]!=0){
        segmentTree[nodeIndex] = (right - left + 1) - segmentTree[nodeIndex];
        if(left!=right){
            lazy[2*nodeIndex + 1] = 1 - lazy[2*nodeIndex + 1];
            lazy[2* nodeIndex + 2] = 1 - lazy[2*nodeIndex + 2];
        }

        lazy[nodeIndex] = 0;
    }

    //If not in range
    if(right< l || left > r){
        return;
    }

    //If [left, right] is completely inside [l, r]
    if(left>=l && right<=r){
        segmentTree[nodeIndex] = right - left + 1 - segmentTree[nodeIndex];
        if(left!=right){
            lazy[2*nodeIndex + 1] = 1 - lazy[2*nodeIndex + 1];
            lazy[2*nodeIndex + 2] = 1 - lazy[2*nodeIndex + 2];
        }
        return;
    }

    //if partially overlap
    int mid = getMid(left, right);
    updateRangeValueUtil(segmentTree, lazy, v, left, mid, 2*nodeIndex + 1, l, r);
    updateRangeValueUtil(segmentTree, lazy, v, mid + 1, right, 2*nodeIndex + 2, l, r);
    segmentTree[nodeIndex] = segmentTree[2*nodeIndex + 1] + segmentTree[2* nodeIndex + 2];
}

int getBlack(vi &segmentTree, vi &lazy, vi &v, int l, int r){
    if(l < 0 || r > v.size() - 1 || r<l){
        return 0;
    } 
    cout<<"Counting black for range"<<l<<' '<<r<<endl;
    return getBlackUtil(segmentTree, lazy, v, 0, v.size() - 1, 0, l, r);
}

void updateRangeValue(vi &segmentTree, vi &lazy, vi &v, int l, int r){
    if(l<0|| r>v.size() - 1 || r<l){
        return;
    }

    updateRangeValueUtil(segmentTree, lazy, v, 0, v.size() - 1, 0, l, r);
}

void constructSegmentTree(vi &segmentTree, vi &lazy, vi &v){
    int height = (int)ceil(log2(v.size()));
    int maxSize = 2*(int)pow(2, height) - 1;

    segmentTree.resize(maxSize, 0);
    lazy.resize(maxSize, 0);
}

int main(){
    int n;
    cin>>n;
    vi v(n);
    for(int i = 0; i<n; i++) v[i] = 0;

    vi segmentTree, lazy;

    constructSegmentTree(segmentTree, lazy, v);
    int t, q, l, r;
    cin>>t;
    while(t--){
        cout<<"Enter Query: ";  
        cin>>q;
        if(q == 1){
            cin>>l>>r;
            updateRangeValue(segmentTree, lazy, v, l, r);
        }
        else{
            cin>>l>>r;
            cout<<getBlack(segmentTree, lazy, v, l, r)<<endl;
        }
    }
}