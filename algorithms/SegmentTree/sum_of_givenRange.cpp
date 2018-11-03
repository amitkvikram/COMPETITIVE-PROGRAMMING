#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define rep(i, a, b) for(int i = 0; i<n; i++)

int getMid(int left, int right){
    return left + (right - left)/2;
}

int gelLeftChild(int nodeIndex){
    return 2*nodeIndex+1;
}

int getRightChild(int nodeIndex){
    return 2*nodeIndex + 2;
}

void updateValueHelper(vi *segment_tree_ptr, int left, int right, int index, int diff, int nodeIndex){
    //If index is not in range of corresponding node [left, right]
    if(left>index || right<index) return;
    (*segment_tree_ptr)[nodeIndex]+=diff;

    if(left == right){    //Leaf Node
        cout<<"Leaf Node = "<<left<<endl<<"index = "<<index<<endl;;
        return;
    }          
    int mid = getMid(left, right);
    updateValueHelper(segment_tree_ptr, left, mid, index, diff, 2*nodeIndex+1);
    updateValueHelper(segment_tree_ptr, mid + 1, right, index, diff, 2*nodeIndex + 2);

    (*segment_tree_ptr)[nodeIndex] = (*segment_tree_ptr)[2 * nodeIndex + 1] +
                                     (*segment_tree_ptr)[2 * nodeIndex + 2];
}

void updateValue(vi *segment_tree_ptr, int index, vi &v, int value){
    if(index<0 || index>v.size() - 1) return;
    v[index] = value;

    updateValueHelper(segment_tree_ptr, 0, v.size() - 1, index, diff, 0);
}

int getSumHelper(vi *segment_tree_ptr, int left, int right, int nodeIndex, int l, int r){
    //If range [l, r] is completely outside of [left, right]@No overlap
    if(left > r || right < l){
        return 0;
    }

    //If range [left, right] is completely inside of [l, r]
    if(left>=l && right<=r){
        return (*segment_tree_ptr)[nodeIndex];
    }

    //Upto now we have handled the case left == right because then range [left, right] will either be completely inside [l, r]
    //OR there will be no overlap b/w [l, r] and [left, right]
    //If there is overlap between [l, r] and [left, right]
    int mid = getMid(left, right);
    return getSumHelper(segment_tree_ptr, left, mid, 2*nodeIndex+1, l, r)+
        getSumHelper(segment_tree_ptr, mid + 1, right, 2*nodeIndex + 2, l, r);
}

int getSum(vi *segment_tree_ptr, vi &v, int l, int r){
    //Check for invalide renge
    if(l<0 || r > v.size() - 1 || l>r){
        // cout<<"Invalid Idex";
        return 0;
    }

    return getSumHelper(segment_tree_ptr, 0, v.size() - 1, 0, l, r);
}

//left and right indices are inclusive
int constructSegmentTreeHelper(vi &v, int left, int right, vi *segment_tree_ptr, int nodeIndex){
    //if only one element=> leaf node
    if(left == right){
        (*segment_tree_ptr)[nodeIndex] = v[left];
        return v[left];
    }

    int mid = getMid(left, right);
    (*segment_tree_ptr)[nodeIndex] = constructSegmentTreeHelper(v, left, mid, segment_tree_ptr, gelLeftChild(nodeIndex)) + 
                                    constructSegmentTreeHelper(v, mid + 1, right, segment_tree_ptr, getRightChild(nodeIndex));
    return (*segment_tree_ptr)[nodeIndex];
}

vector<int> & constructSegmentTree(vi &v){
    int height = int(ceil(log2(v.size())));
    int max_size = 2*(int)pow(2, height) - 1;
    vector<int> *segment_tree_ptr = new vector<int>(max_size);

    constructSegmentTreeHelper(v, 0, v.size() - 1, segment_tree_ptr, 0);

    return *segment_tree_ptr;
}

int main(){
    int n;
    cin>>n;
    vi v(n);
    rep(i, 0, n){
        cin>>v[i];
    }

    vector<int> &segment_tree = constructSegmentTree(v);
    // cout<<&(segment_tree)<<endl;

    int t, q, l , r, val;
    cin>>t;
    while(t--){
        cout<<"Enter Query: ";
        cin>>q;
        if(q == 1){
            cout<<"Query 1\n";
            cin>>l>>val;
            updateValue(&segment_tree, l, v, val);
        }
        else{
            cout<<"Query 2\n";
            cin>>l>>r;
            cout<<getSum(&segment_tree, v, l, r)<<endl;;
        }
    } 

    delete &segment_tree;
}