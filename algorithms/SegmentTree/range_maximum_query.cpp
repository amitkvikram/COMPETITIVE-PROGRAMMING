#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int getMid(int left, int right){
    return left + (right - left)/2;
}

void updateValueHelper(vi &v, vi &segmentTree, int left, int right, int nodeIndex, int val, int index){
    if(index < left || index > right) return;

    if(left == right){
        // cout<<"left = "<<left<   <" Index = "<<index<<endl;
        segmentTree[nodeIndex] = val;
        return;
    }

    int mid = getMid(left, right);

    updateValueHelper(v, segmentTree, left, mid, 2*nodeIndex + 1, val, index);
    updateValueHelper(v, segmentTree, mid + 1, right, 2*nodeIndex + 2, val , index);

    segmentTree[nodeIndex] = max(segmentTree[2*nodeIndex + 1], segmentTree[2*nodeIndex + 2]);
}

void updateValue(vi &v, vi &segmentTree, int index, int val){
    if(index <0 || index > v.size() - 1){
        return;
    }
    v[index] = val;
    cout<<"Updating index and value: "<<index<<" "<<val<<endl;
    updateValueHelper(v, segmentTree, 0, v.size() - 1, 0, val, index);
}

int getMaxHelper(vi &v, vi &segmentTree, int left, int right, int nodeIndex, int l, int r){
    //If no overlap
    if(left > r || right < l){
        return INT_MIN;
    }

    //If [left, right] is completrly inside [l, r]
    if(left >= l && right <= r){
        return segmentTree[nodeIndex];
    }

    int mid = getMid(left, right);

    return max(getMaxHelper(v, segmentTree, left, mid, 2*nodeIndex + 1, l, r),
                getMaxHelper(v, segmentTree, mid + 1, right, 2*nodeIndex + 2, l, r));
}

int getMax(vi &v, vi &segmentTree, int l, int r){
    if(l<0 || r>v.size()-1 || r<l){
        return 0;
    }

    return getMaxHelper(v, segmentTree, 0, v.size() - 1, 0, l, r);
}

int constructSegmentTreeHelper(vi &v, vi &segmentTree, int left, int right, int nodeIndex){
    //If leaf node
    if(left == right){
        segmentTree[nodeIndex] = v[left];
        return v[left];
    }

    int mid = getMid(left, right);

    segmentTree[nodeIndex] = max(constructSegmentTreeHelper(v, segmentTree, left, mid, 2*nodeIndex + 1),
                            constructSegmentTreeHelper(v, segmentTree, mid + 1, right, 2* nodeIndex + 2));
    
    return segmentTree[nodeIndex];
}

vi & constructSegmentTree(vi &v){
    int height = (int)ceil(log2(v.size()));
    int maxSize = 2*(int)pow(2, height) - 1;

    vi *segmentTreePtr = new vi(maxSize);
    constructSegmentTreeHelper(v, *segmentTreePtr, 0, v.size() - 1, 0);
    return *segmentTreePtr;
}

int main(){
    int n;
    cin>>n;

    vi v(n);
    for(int i = 0; i<n; i++) cin>>v[i];

    vi &segmentTree = constructSegmentTree(v);
    int t, index, val, l, r;
    cin>>t;
    while(t--){
        int q;
        cout<<"Enter Query: ";
        cin>>q;
        if(q == 1){
            cin>>index>>val;
            updateValue(v, segmentTree, index, val);
        }
        else{
            cin>>l>>r;
            cout<<"Max in Range: "<<getMax(v, segmentTree, l, r)<<endl;
        }
    }
}