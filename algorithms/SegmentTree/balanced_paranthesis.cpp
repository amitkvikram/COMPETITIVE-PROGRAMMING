#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<char> vc;

class segmentTreeNode{
    public:
    int ans;
    int openingBracket;
    int closingBracket;
    segmentTreeNode(){}
    segmentTreeNode(int a, int b, int c){
        ans = a;
        openingBracket = b;
        closingBracket = c;
    }
};

int getMid(int left, int right){
    return left + (right - left )/2;
}

segmentTreeNode getValueUtil(vector<segmentTreeNode> &segmentTree,vc &v, int left, int right, int nodeIndex, int l, int r){
    //If out of range
    if(left > r || right<l){
        return segmentTreeNode{0,0,0};
    }

    //If [left, right] lies completely inside [l, r]
    if(left>=l && right<=r){
        return segmentTree[nodeIndex];
    }

    segmentTreeNode dummy;

    //If partial overlap
    int mid = getMid(left, right);
    segmentTreeNode leftNode =  getValueUtil(segmentTree, v, left, mid, 2*nodeIndex+1, l, r);
    segmentTreeNode rightNode = getValueUtil(segmentTree, v, mid + 1, right, 2*nodeIndex + 2, l, r);

    dummy.ans = leftNode.ans + rightNode.ans + min(leftNode.openingBracket, rightNode.closingBracket);
    dummy.openingBracket = leftNode.openingBracket + rightNode.openingBracket - min(leftNode.openingBracket,
                            rightNode.closingBracket);
    dummy.closingBracket = leftNode.closingBracket + rightNode.closingBracket - min(leftNode.openingBracket,
                            rightNode.closingBracket);
    return dummy;
}

int getValue(vector<segmentTreeNode> &segmentTree, vc &v, int l, int r){
    if(l< 0 || r>v.size() - 1|| r<l){
        return 0;
    }

    segmentTreeNode dummy = getValueUtil(segmentTree, v, 0, v.size() - 1, 0, l, r);
    return dummy.ans;
}

void constructSegmentTreeUtil(vector<segmentTreeNode> &segmentTree, vc &v, int left, int right, int nodeIndex){
    //If leaf node
    if(left == right){
        if(v[left] == '(') segmentTree[nodeIndex].openingBracket = 1;
        else segmentTree[nodeIndex].closingBracket = 1;
        return;
    }

    int mid = getMid(left, right);

    constructSegmentTreeUtil(segmentTree, v, left, mid, 2*nodeIndex + 1);
    constructSegmentTreeUtil(segmentTree, v, mid + 1, right, 2*nodeIndex + 2);
    segmentTree[nodeIndex].ans = segmentTree[2*nodeIndex + 1].ans + segmentTree[2*nodeIndex + 2].ans + min(
        segmentTree[2*nodeIndex + 1].openingBracket, segmentTree[2*nodeIndex + 2].closingBracket);
    segmentTree[nodeIndex].openingBracket = segmentTree[2*nodeIndex + 1].openingBracket +
                            segmentTree[2*nodeIndex + 2].openingBracket - min(segmentTree[2*nodeIndex + 1].openingBracket,
                                segmentTree[2 * nodeIndex + 2].closingBracket);
    segmentTree[nodeIndex].closingBracket = segmentTree[2*nodeIndex + 1].closingBracket + 
                            segmentTree[2*nodeIndex + 2].closingBracket - min(segmentTree[2*nodeIndex + 1].openingBracket,
                            segmentTree[2*nodeIndex + 2].closingBracket);
 }

void constructSegmentTree(vector<segmentTreeNode> &segmentTree, vc &v){
    int height = (int)ceil(log2(v.size()));
    int maxSize = 2*(int)pow(2, height) - 1;

    segmentTree.resize(maxSize, {0, 0, 0});

    constructSegmentTreeUtil(segmentTree, v, 0, v.size() - 1, 0);
}

int main(){
    int n;
    cin>>n;
    vc v(n);
    for(int i =0; i<n; i++) cin>>v[i];

    vector<segmentTreeNode> segmentTree;

    constructSegmentTree(segmentTree, v);
    int t, q, l, r;
    cin>>t;
    while(t--){
        cout<<"Enter l,r: ";
        cin>>l>>r;
        cout<<getValue(segmentTree, v, l, r)<<endl;   
    }
}