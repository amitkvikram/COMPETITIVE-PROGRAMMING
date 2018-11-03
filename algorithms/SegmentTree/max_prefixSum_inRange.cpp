#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int getMid(int left, int right){
    return left + (right - left)/2;
}

class stnode{
    public:
      int tot;
      int prefixSum;
};

void constructUtil(int left, int right, int nodeIndex, vi &v, vector<stnode> &st){
    //if leaf node
    if(left == right){
        st[nodeIndex].tot = v[left];
        st[nodeIndex].prefixSum = v[left];
        return;
    }

    int mid = getMid(left, right);

    constructUtil(left, mid, 2 * nodeIndex + 1, v, st);
    constructUtil(mid + 1, right, 2*nodeIndex + 2, v, st);

    st[nodeIndex].tot = st[2 * nodeIndex + 1].tot + st[2 * nodeIndex + 2].tot;
    st[nodeIndex].prefixSum = max(st[2 * nodeIndex + 1].prefixSum, st[2 * nodeIndex + 1].tot + st[2 * nodeIndex + 2].prefixSum);
}

void construct(int n, vi &v, vector<stnode> &st){
    int height = (int)ceil(log2(n));
    int sz = 2 * (int)pow(2, height);
    st.resize(sz);

    constructUtil(0, v.size() - 1, 0, v, st);
}

stnode getPrefixSumUtil(int left, int right, int nodeIndex, int l, int r, vi &v, vector<stnode> &st){
    //if [left, right] lies completely inside [l, r]
    if(left >= l && right<=r){
        return st[nodeIndex];
    }

    int mid = getMid(left, right);
    //if [left, right] lies in left of mid
    if(r<=mid){
        return getPrefixSumUtil(left, mid, 2 * nodeIndex + 1, l, r, v, st);
    }
    //if [left, right] lies in right of mid
    if(l > mid){
        return getPrefixSumUtil(mid + 1, right, 2 * nodeIndex + 2, l, r, v, st);
    }

    stnode leftNode = getPrefixSumUtil(left, mid, 2 * nodeIndex + 1, l, r, v, st);
    stnode rightNode = getPrefixSumUtil(mid + 1, right, 2 * nodeIndex + 2, l, r, v, st);
    stnode dummy;
    dummy.tot = leftNode.tot + rightNode.tot;
    dummy.prefixSum = max(leftNode.prefixSum, leftNode.tot + rightNode.prefixSum);
    return dummy;
}

int getPrefixSum(int l, int r, vi &v, vector<stnode> &st){
    stnode dummy = getPrefixSumUtil(0, v.size() - 1, 0, l, r, v, st);
    return dummy.prefixSum;
}

int main(){
    int n, q;
    cin >> n >> q;
    vi v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<stnode> st;
    construct(n, v, st);

    int l, r;
    while(q--){
        cin >> l >> r;
        cout<<getPrefixSum(l, r, v, st)<<endl;
    }
}