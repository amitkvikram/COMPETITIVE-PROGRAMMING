#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;

vii v, st;
int num;

int getMid(int left, int right){
    return left + (right - left) / 2;
}

void mergeVector(vi &L, vi &R, vi &v){
    int i = 0, j = 0, k = 0;
    while(i < L.size() && j<R.size()){
        if(L[i] < R[j]){
            v.push_back(L[i]);
            i++;
        }
        else{
            v.push_back(R[j]);
            j++;
        }
    }

    while(i < L.size()){
        v.push_back(L[i]);
        i++;
    }

    while( j< R.size()){
        v.push_back(R[j]);
        j++;
    }
}

int getCntUtil(int left, int right, int nodeIndex, int l, int r){
    //if [left, right] lies competely inside [l, r]
    if(left >= l && right <=r){
        int cnt = upper_bound(st[nodeIndex].begin(), st[nodeIndex].end(), num) - st[nodeIndex].begin();
        return cnt;
    }

    int mid = getMid(left, right);
    //if [l, r] is in left of mid
    if(r<=mid)
        return getCntUtil(left, mid, 2 * nodeIndex + 1, l, r);
    // if [l, r] is in right of mid
    if(l>mid) return getCntUtil(mid + 1, right, 2*nodeIndex + 2, l, r);

    return getCntUtil(left, mid, 2 * nodeIndex + 1, l, r) +
           getCntUtil(mid + 1, right, 2 * nodeIndex + 2, l, r);
}

int getCnt(int l, int r){
    if(l<0 || r>v.size() - 1 || r<l){
        return 0;
    }

    return getCntUtil(0, v.size() - 1, 0, l, r);
}

void constructUtil(int left, int right, int nodeIndex){
    //if leaf node
    if(left == right){
        st[nodeIndex] = v[left];
        return;
    }

    int mid = getMid(left, right);

    constructUtil(left, mid, 2 * nodeIndex + 1);
    constructUtil(mid + 1, right, 2 * nodeIndex + 2);

    mergeVector(st[2 * nodeIndex + 1], st[2 * nodeIndex + 2], st[nodeIndex]);
}

void construct(int n){
    int height = (int)ceil(log2(n));
    int sz = 2 * (int)pow(2, height) - 1;

    st.resize(sz);

    constructUtil(0, n - 1, 0);
}

int main(){
    int n, q;
    cin >> n >> q;

    v.resize(n);
    for (int i = 0; i < n; i++){
        v[i].resize(n);
        for (int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }

    construct(n);
    cout << "Segment Tree Constructed\n";
    int l, r;
    while (q--)
    {
        cin >> l >> r >> num;
        cout << getCnt(l, r)<<endl;
    }
}