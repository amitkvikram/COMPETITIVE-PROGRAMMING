#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define sz size()

int getMid(int left, int right){
    return left + (right - left)/2;
}

class segmentTreeNode{
    public:
    int maxFreq;
    int lastElem;
    int lastElemFreq;
    int firstElem;
    int firstElemFreq;
};

typedef vector<segmentTreeNode> vs;

segmentTreeNode getFreqUtil(vs &segmentTree, vi &v, int left, int right, int nodeIndex, int l, int r){
    //If no overlap
    // cout<<"getFreqUtil Called\n";

    //if [left, right] is completely inside [l, r]
    if(left>=l && right<=r){
        return segmentTree[nodeIndex];
    }

    int mid = getMid(left, right);

    if(r<=mid) return getFreqUtil(segmentTree, v, left, mid, 2*nodeIndex + 1, l, r);
    if(l>mid) return getFreqUtil(segmentTree, v, mid + 1,  right, 2*nodeIndex + 2, l, r);

    segmentTreeNode leftNode = getFreqUtil(segmentTree, v, left, mid , 2*nodeIndex + 1, l, r);
    segmentTreeNode rightNode = getFreqUtil(segmentTree, v, mid + 1, right, 2*nodeIndex + 2, l, r);

    segmentTreeNode dummy;
    int temp;
    dummy.lastElem = rightNode.lastElem;
    dummy.firstElem = leftNode.firstElem;

    if(leftNode.lastElem == rightNode.firstElem){
        temp = leftNode.lastElemFreq + rightNode.firstElemFreq;

        if(rightNode.lastElemFreq == (right - mid)){
            dummy.lastElemFreq = temp;
        }
        else dummy.lastElemFreq = rightNode.lastElemFreq;

        if(leftNode.firstElemFreq == (mid - left + 1)){
            dummy.firstElemFreq = temp;
        }
        else dummy.firstElemFreq = leftNode.firstElemFreq;

        dummy.maxFreq = max(leftNode.maxFreq, max(rightNode.maxFreq,
                                            temp));
    }
    else{
        dummy.firstElemFreq = leftNode.firstElemFreq;
        dummy.lastElemFreq = rightNode.lastElemFreq;
        dummy.maxFreq = max(leftNode.maxFreq, rightNode.maxFreq);
    }

    return dummy;
}

segmentTreeNode getFreq(vs &segmentTree, vi &v, int l, int r){
    segmentTreeNode dummy;
    dummy.firstElem = dummy.firstElemFreq = dummy.maxFreq = dummy.lastElem = dummy.lastElemFreq = 0;
    if(l < 0 || r > v.sz - 1 || r<l){
        return dummy;
    }

    return getFreqUtil(segmentTree, v, 0, v.sz - 1, 0, l, r);
}

void constructSegmentTreeUtil(vs &segmentTree, vi &v, int left, int right, int nodeIndex){
    //If Leaf Node
    if(left == right){
        segmentTree[nodeIndex].maxFreq = 1;
        segmentTree[nodeIndex].lastElem = v[left];
        segmentTree[nodeIndex].lastElemFreq = 1;
        segmentTree[nodeIndex].firstElem = v[left];
        segmentTree[nodeIndex].firstElemFreq = 1;
        return;
    }

    int mid = getMid(left, right);
    constructSegmentTreeUtil(segmentTree, v, left, mid, 2*nodeIndex + 1);
    constructSegmentTreeUtil(segmentTree, v, mid + 1, right, 2*nodeIndex + 2);
    int temp;
    segmentTree[nodeIndex].lastElem = segmentTree[2*nodeIndex + 2].lastElem;
    segmentTree[nodeIndex].firstElem = segmentTree[2*nodeIndex + 1].firstElem;

    if(segmentTree[2*nodeIndex + 1].lastElem == segmentTree[2*nodeIndex + 2].firstElem){
        temp = segmentTree[2*nodeIndex + 1].lastElemFreq + segmentTree[2*nodeIndex + 2].firstElemFreq;

        if(segmentTree[2*nodeIndex + 2].lastElemFreq == (right - mid)){
            segmentTree[nodeIndex].lastElemFreq = temp;
        }
        else segmentTree[nodeIndex].lastElemFreq = segmentTree[2*nodeIndex +2].lastElemFreq;

        if(segmentTree[2*nodeIndex + 1].firstElemFreq == (mid - left + 1)){
            segmentTree[nodeIndex].firstElemFreq = temp;
        }
        else segmentTree[nodeIndex].firstElemFreq = segmentTree[2*nodeIndex +1].firstElemFreq;

        segmentTree[nodeIndex].maxFreq = max(segmentTree[2*nodeIndex + 1].maxFreq, max(segmentTree[2*nodeIndex + 2].maxFreq,
                                            temp));
    }
    else{
        segmentTree[nodeIndex].firstElemFreq = segmentTree[2*nodeIndex +1].firstElemFreq;
        segmentTree[nodeIndex].lastElemFreq = segmentTree[2*nodeIndex +2].lastElemFreq;
        segmentTree[nodeIndex].maxFreq = max(segmentTree[2*nodeIndex + 1].maxFreq,segmentTree[2*nodeIndex + 2].maxFreq);
    }
}

void constructSegmentTree(vs &segmentTree, vi &v){
    int height = (int)ceil(log2(v.sz));
    int maxSize = 2*(int)pow(2, height) - 1;

    segmentTree.resize(maxSize);

    constructSegmentTreeUtil(segmentTree, v, 0, v.sz - 1, 0);
}

int main(){
    int n;
    cin>>n;
    vi v(n);

    for(int i = 0; i<n; i++){
        cin>>v[i];
    }

    vs segmentTree;
    constructSegmentTree(segmentTree, v);
    int t, l, r;
    cin>>t;
    while(t--){
        cout<<"Enter l , r: ";
        cin>>l>>r;
        segmentTreeNode dummy =  getFreq(segmentTree, v, l, r);
        cout<<dummy.maxFreq<<endl;
    }
}