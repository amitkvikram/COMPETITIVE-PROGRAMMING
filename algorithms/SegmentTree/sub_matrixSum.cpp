#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define rep(i, a, b) for(int i = a;i<b; i++)

int getMid(int left, int right){
    return left+(right - left)/2;
}

void vectorSum(vi &v1, vi &v2, vi &v3){
    rep(i, 0, v1.size()){
        v3[i] = v1[i] + v2[i];
    }
}

void updataValueForRow(vvi &segmentTree, int nodeRowIndex, int left, int right, int nodeColIndex, int col, int diff){
    //If col is out of range [left, right]
    if(col<left || col>right){
        return;
    }

    //If leaf node
    if(left == right){
        cout<<"Updating value in row for: "<<left<<endl;
        segmentTree[nodeRowIndex][nodeColIndex] += diff;
        return;
    }

    int mid = getMid(left, right);
    
    updataValueForRow(segmentTree, nodeRowIndex, left, mid, 2*nodeColIndex + 1, col, diff);
    updataValueForRow(segmentTree, nodeRowIndex, mid + 1, right, 2*nodeColIndex + 2, col, diff);

    segmentTree[nodeRowIndex][nodeColIndex] = segmentTree[nodeRowIndex][2*nodeColIndex + 1] + 
                                              segmentTree[nodeRowIndex][2*nodeColIndex + 2];
}

void updateValueHelper(vvi &segmentTree, vvi &v, int left, int right, int nodeIndex, int row, int col, int diff){
    //If index is not in range
    if(row<left || row>right){
        return;
    }

    //leaf node
    if(left == right){
        cout<<"Calling Update for row: "<<left<<endl;
        updataValueForRow(segmentTree, nodeIndex, 0, v[0].size() - 1, 0, col, diff);
        return;
    }

    //Else update value

    int mid = getMid(left, right);

    updateValueHelper(segmentTree, v, left, mid, 2*nodeIndex + 1, row, col, diff);
    updateValueHelper(segmentTree, v, mid + 1, right, 2*nodeIndex + 2, row, col, diff);
    // vectorSum(segmentTree[2*nodeIndex + 2], segmentTree[2*nodeIndex + 1], segmentTree[nodeIndex]);
    updataValueForRow(segmentTree, nodeIndex, 0, v[0].size() - 1, 0, col, diff);
}

void updateValue(vvi &segmentTree, vvi &v, int val, int row, int col){
    if(row<0 || row>v.size() - 1 || col<0 || col>v[0].size() - 1){
        cout<<"Invalid Index\n";
        return;
    }
    int diff = val - v[row][col];
    v[row][col] = val;

    updateValueHelper(segmentTree, v, 0, v.size() - 1, 0, row, col, diff);
}

int getSumForRow(vvi &segmentTree, int nodeRowIndex, int left, int right,int nodeColIndex, int colStart, int colEnd){
    //if no overlap of [left, right] and [colStart, colEnd]
    if(left > colEnd || right< colStart){
        return 0;
    }

    //Else if[left, right] is completely inside [colStart, colEnd]
    if(left>= colStart && right<=colEnd){
        return segmentTree[nodeRowIndex][nodeColIndex];
    }

    //Else if they overlap but not completely
    int mid = getMid(left, right);

    return getSumForRow(segmentTree, nodeRowIndex, left, mid, 2*nodeColIndex + 1, colStart, colEnd)+
        getSumForRow(segmentTree, nodeRowIndex, mid + 1, right, 2*nodeColIndex + 2, colStart, colEnd);

}

int getSumHelper(vvi &segmentTree, vvi &v, int left, int right, int nodeIndex, int rowStart, int rowEnd, int colStart, int colEnd){
    //If no overlap of [left, right] and [rowStart, rowEnd]
    if(left > rowEnd || right<rowStart){
        return 0;
    }

    //Else if [left, right] is completely inside [rowStart, rowEnd]
    if(left>=rowStart && right<=rowEnd){
        return getSumForRow(segmentTree, nodeIndex, 0, v[0].size() - 1, 0, colStart, colEnd);
    }

    //Else if they overlap but not completely
    int mid = getMid(left, right);

    return getSumHelper(segmentTree, v, left, mid, 2*nodeIndex + 1, rowStart, rowEnd, colStart, colEnd)+
        getSumHelper(segmentTree, v, mid + 1, right, 2*nodeIndex + 2, rowStart, rowEnd, colStart, colEnd);

}

int getSum(vvi &segmentTree, vvi &v, int rowStart, int rowEnd, int colStart, int colEnd){
    if(rowStart<0 || rowEnd>v.size() - 1 || rowEnd<rowStart||colStart<0 || colEnd>v[0].size() - 1|| colEnd<colStart){
        cout<<"Invalid Index\n";
        return 0;
    }

    return getSumHelper(segmentTree,v, 0, v.size() - 1, 0, rowStart, rowEnd, colStart, colEnd);
}

int constructSegmentForRow(vvi &v, int row, int left, int right, int nodeColIndex, int nodeRowIndex, vvi &segmentTree){
    //if leaf node
    if(left == right){
        segmentTree[nodeRowIndex][nodeColIndex] = v[row][left];
        return v[row][left];
    }

    int mid = getMid(left, right);

    segmentTree[nodeRowIndex][nodeColIndex] = constructSegmentForRow(v, row, left, mid, 2*nodeColIndex + 1, nodeRowIndex, segmentTree)+
                                constructSegmentForRow(v, row, mid + 1, right, 2*nodeColIndex + 2, nodeRowIndex, segmentTree);
    return segmentTree[nodeRowIndex][nodeColIndex];

}

vi& constructSegmentTreeHelper(vvi &v, int left, int right, vvi &segmentTree, int nodeIndex){
    if(left == right){
        constructSegmentForRow(v, left, 0, v[0].size() - 1, 0, nodeIndex, segmentTree);
        return segmentTree[nodeIndex];
    }

    int mid = getMid(left, right);

    vi &leftChild = constructSegmentTreeHelper(v, left, mid, segmentTree, 2*nodeIndex + 1);
    vi &rightChild = constructSegmentTreeHelper(v, mid + 1, right, segmentTree, 2*nodeIndex + 2);

    vectorSum(leftChild, rightChild, segmentTree[nodeIndex]);

    return segmentTree[nodeIndex];
}

vvi &constructSegmentTree(vvi &v, int n, int m){
    int rowHeight = (int)ceil(log2(n)), colHeight = (int)ceil(log2(m));
    int maxRowSize = 2*(int)pow(2, rowHeight) - 1, maxColSize = 2*(int)pow(2, colHeight) - 1;

    vvi *segmentTreePtr = new vvi (maxRowSize, vector<int>(maxColSize));

    constructSegmentTreeHelper(v, 0, v.size() - 1, *segmentTreePtr, 0);
    return *segmentTreePtr;
}

int main(){
    int n, m;   //row, col
    cin>>n>>m;
    vvi v(n, vector<int> (m));
    rep(i, 0, n) 
        rep(j, 0, m) cin>>v[i][j];

    vvi &segmentTree = constructSegmentTree(v, n, m);
    int t, q, rowStart, rowEnd, colStart, colEnd, row, col, val;
    cin>>t;
    while(t--){
        cout<<"Enter Query: ";
        cin>>q;
        if(q == 1){
            cin>>row>>col>>val;
            updateValue(segmentTree, v, val, row, col);
        }
        else{
            cin>>rowStart>>rowEnd>>colStart>>colEnd;
            cout<<getSum(segmentTree, v, rowStart, rowEnd, colStart, colEnd)<<endl;
        }
    }
}