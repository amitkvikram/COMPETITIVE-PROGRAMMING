#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class segmentTreeNode{
    public:
    int maxSum;
    int Sum;
    int prefixSum;
    int suffixSum;
    segmentTreeNode(){}
    segmentTreeNode(int a, int b, int c, int d){
        maxSum = a, Sum = b, prefixSum = c, suffixSum = d;
    }
};


typedef vector<segmentTreeNode> vs;

int getMid(int left, int right){
    return left + (right - left)/2;
}

segmentTreeNode getValUtil(vs &segmentTree, vi &v, int left, int right, int nodeIndex, int l, int r){
    //If no overlap b/w [left, right] and [l, r]

    //if completely in range
    if(left >= l && right <=r){
        return segmentTree[nodeIndex];
    }

    int mid = getMid(left, right);
    if( r<=mid )  return getValUtil(segmentTree, v, left, mid, 2*nodeIndex + 1, l, r);
    else if(l>mid) return getValUtil(segmentTree, v, mid + 1, right, 2*nodeIndex + 2, l, r);

    segmentTreeNode leftNode = getValUtil(segmentTree, v, left, mid, 2*nodeIndex + 1, l, r);
    segmentTreeNode rightNode = getValUtil(segmentTree, v, mid + 1, right, 2*nodeIndex + 2, l, r);

    segmentTreeNode dummy;
    dummy.Sum = leftNode.Sum + rightNode.Sum;
    dummy.prefixSum = max(leftNode.prefixSum, leftNode.Sum + rightNode.prefixSum);
    dummy.suffixSum = max(rightNode.suffixSum, leftNode.suffixSum + rightNode.Sum);
    dummy.maxSum = max(leftNode.maxSum, max(rightNode.maxSum, max(dummy.prefixSum, max(dummy.suffixSum,
                                                              (leftNode.suffixSum + rightNode.prefixSum)))));
    return dummy;
}

int getVal(vs &segmentTree, vi &v, int l, int r){
    if(l < 0 || r> v.size() - 1 || r< l){
        cout<<"Invalid Index\n";
        return 0;
    }

    segmentTreeNode dummy = getValUtil(segmentTree, v, 0, v.size() - 1, 0, l, r);
    return dummy.maxSum;
}

void updateValUtil(vs &segmentTree, vi &v, int ind, int val, int left, int right, int nodeIndex){
    //if ind not in range
    if(ind < left || ind > right){
        return;
    }

    //if leaf node
    if(left == right){
        segmentTree[nodeIndex] = {val, val, val, val};
        return;
    }

    int mid = getMid(left, right);
    updateValUtil(segmentTree, v, ind, val, left, mid , 2*nodeIndex + 1);
    updateValUtil(segmentTree, v, ind, val, mid + 1, right, 2*nodeIndex + 2);
    segmentTree[nodeIndex].Sum = segmentTree[2*nodeIndex + 1].Sum+ segmentTree[2*nodeIndex + 2].Sum;
    segmentTree[nodeIndex].prefixSum = segmentTree[2*nodeIndex + 1].prefixSum + segmentTree[2*nodeIndex + 2].prefixSum;
    segmentTree[nodeIndex].suffixSum = segmentTree[2*nodeIndex + 1].suffixSum + segmentTree[2*nodeIndex + 2].suffixSum;
    segmentTree[nodeIndex].maxSum = max(segmentTree[2*nodeIndex + 1].maxSum, max(segmentTree[2*nodeIndex+2].maxSum,
                            max(segmentTree[2*nodeIndex+1].prefixSum, max(segmentTree[2*nodeIndex + 2].suffixSum,
                            segmentTree[2*nodeIndex + 1].suffixSum + segmentTree[2*nodeIndex + 2].prefixSum))));
}

void updateVal(vs &segmentTree, vi &v, int ind, int val){
    if(ind < 0 || ind > v.size() - 1){
        cout<<"Invalid Index\n";
        return;
    }

    v[ind] = val;

    updateValUtil(segmentTree, v, ind, val, 0, v.size() - 1, 0);
}

void constructSegmentTreeUtil(vs &segmentTree, vi &v, int left, int right, int nodeIndex){
    //If Leaf Node
    if(left == right){
        segmentTree[nodeIndex].maxSum = v[left];
        segmentTree[nodeIndex].Sum = v[left];
        segmentTree[nodeIndex].prefixSum = v[left];
        segmentTree[nodeIndex].suffixSum = v[left];
        return;
    }

    int mid = getMid(left, right);
    constructSegmentTreeUtil(segmentTree, v, left, mid , 2*nodeIndex + 1);
    constructSegmentTreeUtil(segmentTree, v, mid + 1, right, 2*nodeIndex + 2);
    segmentTreeNode leftNode = segmentTree[2*nodeIndex + 1];
    segmentTreeNode rightNode = segmentTree[2*nodeIndex + 2];
    
    segmentTree[nodeIndex].Sum = leftNode.Sum + rightNode.Sum;
    segmentTree[nodeIndex].prefixSum = max(leftNode.prefixSum, leftNode.Sum + rightNode.prefixSum);
    segmentTree[nodeIndex].suffixSum = max(rightNode.suffixSum, rightNode.Sum + leftNode.suffixSum);
    segmentTree[nodeIndex].maxSum = max(leftNode.maxSum, max(rightNode.maxSum, max(segmentTree[nodeIndex].prefixSum, 
                                    max(segmentTree[nodeIndex].suffixSum, leftNode.suffixSum + rightNode.prefixSum))));
}

void constructSegmentTree(vs &segmentTree, vi &v){
    int height = (int)ceil(log2(v.size()));
    int maxSize = 2*(int)pow(2, height) - 1;

    segmentTree.resize(maxSize);
    constructSegmentTreeUtil(segmentTree, v, 0, v.size() - 1, 0);
}

int main(){
    int n;
    cin>>n;
    vi v(n);
    for(int i = 0; i<n; i++) cin>>v[i];

    vs segmentTree;

    constructSegmentTree(segmentTree, v);
    int t, q, ind, val, l, r;
    cin>>t;
    while(t--){
        cout<<"Enter Query: ";
        cin>>q;
        if(q == 1){
            //Update Value
            cin>>ind>>val;
            updateVal(segmentTree, v, ind, val);
        }
        else{
            //find longest maximum subarray
            cin>>l>>r;
            cout<<getVal(segmentTree, v, l, r)<<endl;
        }
    }
}