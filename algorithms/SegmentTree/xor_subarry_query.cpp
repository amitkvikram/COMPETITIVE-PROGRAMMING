#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int getMid(int left, int right){
    return left + (right - left)/2;
}

void updateValueHelper(vi &segmentTree, int index, int left, int right, int nodeIndex, int diff){
    //If index is not in range 
    if(index<left || index>right) return;

    //If leaf node
    if(left == right){
        cout<<"Updting "<<nodeIndex<<" Index = "<<left<<endl;
        segmentTree[nodeIndex]^=diff;
        return;
    }

    int mid = getMid(left, right);
    updateValueHelper(segmentTree, index, left, mid, 2*nodeIndex + 1, diff);
    updateValueHelper(segmentTree, index, mid + 1, right, 2*nodeIndex + 2, diff);
    segmentTree[nodeIndex] = segmentTree[2*nodeIndex + 1]^segmentTree[2*nodeIndex + 2];
}

void updataValue(vi &segmentTree, vi &v, int index, int val){
    if(index < 0 || index > v.size() - 1){
        cout<<"Invalid Index\n";
        return;
    }
    int diff = val^v[index];
    v[index] = val;
    updateValueHelper(segmentTree, index, 0, v.size() - 1, 0, diff);
}

int  getXorHelper(vi &segmentTree, vi &v, int left, int right, int nodeIndex, int l, int r){
    //If no overlap b/w [left, right] and [l, r]
    if(left > r || l>right){
        return 0;
    }

    //Else if [left, right] is completely inside [l, r]
    if(left>= l && right <= r){
        return segmentTree[nodeIndex];
    }

    int mid = getMid(left, right);
    return getXorHelper(segmentTree, v, left, mid, 2*nodeIndex +1 , l, r)^
                        getXorHelper(segmentTree, v, mid + 1, right, 2*nodeIndex + 2, l, r);
}

int getXor(vi &segmentTree, vi &v, int l, int r){
    if(l<0 || r>v.size() - 1|| r<l){
        cout<<"Invalid Index\n";
        return 0;
    }

    return getXorHelper(segmentTree, v, 0, v.size()  - 1, 0, l, r);
}

void constructSegmentTreeHelper(vi &segmentTree, vi &v, int left, int right, int nodeIndex){
    if(left == right){
        segmentTree[nodeIndex] = v[left];
        return;
    }

    int mid = getMid(left, right);

    constructSegmentTreeHelper(segmentTree, v, left, mid, 2*nodeIndex + 1);
    constructSegmentTreeHelper(segmentTree, v, mid + 1, right, 2*nodeIndex + 2);
    segmentTree[nodeIndex] = segmentTree[2*nodeIndex + 1]^segmentTree[nodeIndex*2 + 2];
}

vi & constructSegmentTree(vi &v){
    int height = (int)ceil(log2(v.size()));
    int maxSize = 2*(int)pow(2, height) - 1;

    vi *segmentTreePtr = new vi(maxSize);

    constructSegmentTreeHelper(*segmentTreePtr, v, 0, v.size() - 1, 0);

    return *segmentTreePtr;
}

int main(){
    int n;
    cin>>n;
    vi v(n);
    for(int i = 0; i<n;i++){
        cin>>v[i];
    }

    vi &segmentTree = constructSegmentTree(v);

    int t, q, ind, l, r, val;
    cin>>t;
    while(t--){
        cout<<"Enter Query: ";
        cin>>q;
        if(q == 1){
            cin>>ind>>val;
            updataValue(segmentTree, v, ind, val);
        }
        else{
            cin>>l>>r;
            cout<<getXor(segmentTree, v, l, r)<<endl;
        }
    }
}