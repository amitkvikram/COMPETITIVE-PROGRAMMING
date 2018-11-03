#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int getMid(int left, int right){
    return left + (right - left)/2;
}

class stnode{
    public:
    int min_elem, min_cnt;
    stnode(){}
    stnode(int a, int b){
        min_elem = a;
        min_cnt = b;
    }
};

void constructUtil(int left, int right, int nodeIndex, vi &v, vector<stnode> &st){
    //if leaf node
    if(left == right){
        st[nodeIndex].min_elem = v[left];
        st[nodeIndex].min_cnt = 1;
        return;
    }

    int mid = getMid(left, right);
    constructUtil(left, mid, 2 * nodeIndex + 1, v, st);
    constructUtil(mid + 1, right, 2 * nodeIndex + 2, v, st);

    if(st[2*nodeIndex + 1].min_elem == st[2*nodeIndex + 2].min_elem){
        st[nodeIndex].min_elem = st[2 * nodeIndex + 1].min_elem;
        st[nodeIndex].min_cnt = st[2 * nodeIndex + 1].min_cnt + st[2 * nodeIndex + 2].min_cnt;
    }
    else if(st[2*nodeIndex + 1].min_elem < st[2*nodeIndex + 2].min_elem){
        st[nodeIndex].min_elem = st[2 * nodeIndex + 1].min_elem;
        st[nodeIndex].min_cnt = st[2 * nodeIndex + 1].min_cnt;
    }
    else{
        st[nodeIndex].min_elem = st[2 * nodeIndex + 2].min_elem;
        st[nodeIndex].min_cnt = st[2 * nodeIndex + 2].min_cnt;
    }
}

void construct(int n, vi &v, vector<stnode> &st){
    int height = (int)ceil(log2(n));
    int sz = 2 * pow(2, height) - 1;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    st.resize(n);

    constructUtil(0, v.size() - 1, 0, v, st);
}

stnode getCntUtil(int left, int right, int nodeIndex, int l, int r, vi &v, vector<stnode> &st){
    //if [left, right] is completely inside [l, r]
    if(left >=l && right<=r){
        // cout << left << " " << right << " " << nodeIndex <<" "<<st[nodeIndex].min_cnt<<" "<<st[nodeIndex].min_elem<<endl;
        return st[nodeIndex];
    }

    int mid = getMid(left, right);
    //if [l, r] is left of mid
    if( r<=mid) return getCntUtil(left, mid, 2*nodeIndex + 1, l, r, v, st);
    //if [l, r] is in right of mid
    if(l > mid)
        return getCntUtil(mid + 1, right, 2 * nodeIndex + 2, l, r, v, st);

    stnode leftNode = getCntUtil(left, mid, 2 * nodeIndex + 1, l, r, v, st);
    stnode rightNode = getCntUtil(mid + 1, right, 2 * nodeIndex + 2, l, r, v, st);
    stnode dummy;

    if(leftNode.min_elem == rightNode.min_elem){
        dummy.min_elem = leftNode.min_elem;
        dummy.min_cnt = leftNode.min_cnt + rightNode.min_cnt;
    }

    else if(leftNode.min_elem < rightNode.min_elem){
        dummy.min_elem = leftNode.min_elem;
        dummy.min_cnt = leftNode.min_cnt;
    }
    else{
       dummy.min_elem = rightNode.min_elem;
       dummy.min_cnt = rightNode.min_cnt;
    }

    return dummy;
}

int getCnt(int l, int r, vi &v, vector<stnode> &st){
    if(l < 0 || r > v.size() - 1 || r<l){
        return 0;
    }

    stnode dummy =  getCntUtil(0, v.size() - 1, 0, l, r, v, st);
    return dummy.min_cnt;
}

int main()
{
    int n, q;
    cin >> n >> q;

    vi v(n);
    vector<stnode> st;
    construct(n, v, st);
    int l, r;
    while (q--)
    {
        cin >> l >> r;
        cout << getCnt(l, r, v, st);
    }
}