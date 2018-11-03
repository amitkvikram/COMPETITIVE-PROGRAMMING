#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class segmentTreeNode{
    public:
    int cnt;
    int Min;
    int gcd;
    segmentTreeNode(){ }
    segmentTreeNode(int a, int b, int c){
        cnt = a;
        Min = b;
        gcd = c;
    }
};

int getMid(int left, int right){
    return left + (right - left)/2;
}

int gcd(int a, int b){
    if(a== 0) return b;
    return gcd(b%a, a);
}

int temp =0;

segmentTreeNode getCountHelper(vector<segmentTreeNode> &segmentTree, vi &v, int left, int right, int nodeIndex, int l, int r){
    // temp++;
    // if(temp>10) return segmentTreeNode{-1, -1, -1};
    // cout<<"node Index = "<<nodeIndex<<endl;
    // return segmentTreeNode{-1, -1, -1};
    //If no overlap
    if(left > r || right < l){
        if(return segmentTreeNode{0, 0, 0};
    }

    //If [left, right] lies completely inside [l, r]
    if(left>=l && right<=r){
        if(segmentTree[nodeIndex].Min == segmentTree[nodeIndex].gcd) return segmentTree[nodeIndex];
        else return segmentTreeNode{0, segmentTree[nodeIndex].Min, segmentTree[nodeIndex].gcd};
    }

    int mid = getMid(left, right);

    segmentTreeNode leftNode = getCountHelper(segmentTree, v, left, mid, 2*nodeIndex + 1, l, r);
    segmentTreeNode rightNode = getCountHelper(segmentTree, v, mid + 1, right, 2* nodeIndex + 2, l, r);

    segmentTreeNode tempNode;
    if(leftNode.gcd && rightNode.gcd){
        tempNode.gcd = gcd(leftNode.gcd, rightNode.gcd);
        tempNode.Min = min(leftNode.Min, rightNode.Min);
        if(tempNode.gcd != tempNode.Min) tempNode.cnt = 0;
        else{
            if(leftNode.Min == rightNode.Min) tempNode.cnt = leftNode.cnt + rightNode.cnt;
            else if(leftNode.Min < rightNode.Min) tempNode.cnt = leftNode.cnt;
            else tempNode.cnt = rightNode.cnt;
        }
        return tempNode;
    }
    else if(leftNode.gcd){
        return leftNode;
    }
    else return rightNode;
}
void getCount(vector<segmentTreeNode> &segmentTree, vi &v, int l, int r){
    if(l<0 || r>v.size() - 1 || r<l){
        return;
    }

    segmentTreeNode tempNode = getCountHelper(segmentTree, v, 0, v.size() - 1, 0, l, r);
    if(tempNode.gcd == tempNode.Min){
        cout<<"GCD = "<<tempNode.gcd<<endl;
        cout<<"Min = "<<tempNode.Min<<endl;
        cout<<"Count = "<<tempNode.cnt<<endl;
    }
    else{
        cout<<"Count = "<<0<<endl;
    }
}

void constructSegmentTreeHelper(vector<segmentTreeNode> &segmentTree, vi &v, int left, int right, int nodeIndex){
    //If leaf Node
    if(left == right){
        segmentTree[nodeIndex].cnt = 1;
        segmentTree[nodeIndex].Min = v[left];
        segmentTree[nodeIndex].gcd = v[left];
        return;
    }

    int mid = getMid(left, right);
    int lChild = 2*nodeIndex + 1, rChild = 2*nodeIndex + 2;

    constructSegmentTreeHelper(segmentTree, v, left, mid, lChild);
    constructSegmentTreeHelper(segmentTree, v, mid + 1, right, rChild);

    segmentTree[nodeIndex].gcd =  gcd(segmentTree[lChild].gcd, segmentTree[rChild].gcd);
    
   if(segmentTree[lChild].Min < segmentTree[rChild].Min){
        segmentTree[nodeIndex].Min = segmentTree[lChild].Min;
        segmentTree[nodeIndex].cnt = segmentTree[lChild].cnt;
    }

    else if(segmentTree[lChild].Min > segmentTree[rChild].Min){
        segmentTree[nodeIndex].Min = segmentTree[rChild].Min;
        segmentTree[nodeIndex].cnt = segmentTree[rChild].cnt; 
    }

    else{
        segmentTree[nodeIndex].Min = segmentTree[rChild].Min;
        segmentTree[nodeIndex].cnt = segmentTree[rChild].cnt + segmentTree[lChild].cnt; 
    }
}

vector<segmentTreeNode> & constructSegmentTree(vi &v){
    int height = (int)ceil(log2(v.size()));
    int maxSize = 2*(int)pow(2, height) - 1;

    vector<segmentTreeNode> *segmentTreePtr = new vector<segmentTreeNode>(maxSize);
    constructSegmentTreeHelper(*segmentTreePtr, v, 0, v.size() - 1, 0);
    return *segmentTreePtr;
}

int main(){
    int n;
    cin>>n;
    vi v(n);
    for(int i = 0; i<n; i++) cin>>v[i];

    vector<segmentTreeNode> &segmentTree = constructSegmentTree(v);
    int t, l, r;
    cin>>t;

    while(t--){
        cin>>l>>r;

        getCount(segmentTree, v, l, r);
    }
}