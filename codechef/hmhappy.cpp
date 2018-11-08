#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b) for(int i = a; i<b; i++)
#define all(v) v.begin(), v.end()

ll sum(vi v){ll init = 0; return accumulate(v.begin(), v.end(), init);}
ll sum(vii v, int check){
    ll init = 0;
    if(check == 1)
    return accumulate(v.begin(), v.end(), init, [](ll a, ii b){
        return a+b.ff;
    });
    else 
    return accumulate(v.begin(), v.end(), init, [](ll a, ii b){
        return a+b.ss;
    });
}
vi prsum(vi v){vi temp(v.size()); rep(i,0,v.size()){if(i>0) 
                temp[i]=temp[i-1]+v[i];else temp[i] = v[i];}return temp;}

const ll mod = 1000000007;  

/*Custom sort
	 sort(v.begin(), v.end(), [](school s1, school s2){
		return s1.c<s2.c;       //this is ordering, if s1.c is less than s2.c 
                then in sorted vector s1 will come before s2 = ascending order
         }); 
*/
    
/*Custom Lower_bound
    int ind = lower_bound(v.begin(), v.end(), 3, [](school s1, int num){
        return num > s1.c;            //num > s1.c should be false at the point at which lower_bound should break
    }) - v.begin();
*/

/*Priority Queue
  priority_queue<school, vector<school>, myCompare> pq;
  
  //myCompare for min Heap according to school.c
  class myCompare{
      public:
      	int operator()(const school &s1, const school &s2){
      		return s1.c > s2.c;
	}
  }

*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

class SegmentTreeNode{
    public:
        int maxCnt;
        int prefixCnt;
        int suffixCnt;
        SegmentTreeNode(){
            maxCnt = 0;
            prefixCnt = 0;
            suffixCnt = 0;
        }
        SegmentTreeNode(int a, int b, int c){
            maxCnt = a;
            prefixCnt = b;
            suffixCnt = c;
        }
};

typedef vector<SegmentTreeNode> vs;

int getMid(int left, int right){
    return left + (right - left)/2;
}

int max1(int a, int b, int c){
    return max(max(a, b), c);
}

void updateUtil(vs &st, vi &v, int ind, int val, int left, int right, int nodeIndex){
    // cout<<ind<<" "<<val<<" "<<" "<<left<<" "<<right<<" "<<nodeIndex<<endl;
    //if ind not in [left, right]
    if(ind < left || ind> right){
        return;
    }

    //if leaf node
    if(left == right){
        st[nodeIndex] = SegmentTreeNode(val, val, val);
        return;
    }

    int mid = getMid(left, right);

    updateUtil(st, v, ind, val, left, mid, 2*nodeIndex + 1);
    updateUtil(st, v, ind, val, mid + 1, right, 2*nodeIndex + 2);

    SegmentTreeNode leftNode = st[2*nodeIndex + 1];
    SegmentTreeNode rightNode = st[2*nodeIndex + 2];

    st[nodeIndex].maxCnt = max1(leftNode.maxCnt, rightNode.maxCnt, leftNode.suffixCnt + rightNode.prefixCnt);
    if(leftNode.prefixCnt == mid - left + 1 && rightNode.prefixCnt > 0){
        st[nodeIndex].prefixCnt = leftNode.prefixCnt + rightNode.prefixCnt;
    }
    else{
        st[nodeIndex].prefixCnt = leftNode.prefixCnt;
    }

    if(rightNode.suffixCnt == right - mid && leftNode.suffixCnt > 0){
        st[nodeIndex].suffixCnt = rightNode.suffixCnt + leftNode.suffixCnt;
    }
    else{
        st[nodeIndex].suffixCnt = rightNode.suffixCnt;
    }
}

void update(vs &st, vi &v, int ind, int val){
    if(ind < 0 || ind > v.size() - 1){
        return;
    }

    v[ind] = val;

    // cout<<"Update: "<<ind<<" "<<val<<endl;

    updateUtil(st, v, ind, val, 0, v.size() - 1, 0);
}

void constructSegmentTreeUtil(vs &st, vi &v, int left, int right, int nodeIndex){
    //if leaf node
    if(left == right){
        st[nodeIndex] = SegmentTreeNode(v[left], v[left], v[left]);
        return;
    }

    int mid = getMid(left, right);
    constructSegmentTreeUtil(st, v, left, mid, 2*nodeIndex + 1);
    constructSegmentTreeUtil(st, v, mid + 1, right, 2*nodeIndex + 2);

    SegmentTreeNode leftNode = st[2*nodeIndex + 1];
    SegmentTreeNode rightNode = st[2*nodeIndex + 2];

    st[nodeIndex].maxCnt = max1(leftNode.maxCnt, rightNode.maxCnt, leftNode.suffixCnt + rightNode.prefixCnt);
    if(leftNode.prefixCnt == mid - left + 1 && rightNode.prefixCnt > 0){
        st[nodeIndex].prefixCnt = leftNode.prefixCnt + rightNode.prefixCnt;
    }
    else{
        st[nodeIndex].prefixCnt = leftNode.prefixCnt;
    }

    if(rightNode.suffixCnt == right - mid && leftNode.suffixCnt > 0){
        st[nodeIndex].suffixCnt = rightNode.suffixCnt + leftNode.suffixCnt;
    }
    else{
        st[nodeIndex].suffixCnt = rightNode.suffixCnt;
    }
}

void constructSegmentTree(vs &st, vi &v){
    int height = (int)ceil(log2(v.size()));
    int maxSize = 2*(int)pow(2, height) - 1;

    st.resize(maxSize);
    constructSegmentTreeUtil(st, v, 0, v.size() - 1, 0);
}

int main(){
    int n, q, k;
    cin>>n>>q>>k;

    int n1 = q + n;
    vector<int> v(n1, 0);

    for(int i = q; i<n1; i++){
        cin>>v[i];
    }

    vs st;

    constructSegmentTree(st, v);

    // cout<<st[0].maxCnt<<endl;

    string s;
    cin>>s;
    int left = q, right = n1 - 1;
    for(int i = 0; i<q; i++){
        if(s[i] == '!'){
            update(st, v, left -1, v[right]);
            update(st, v, right, 0);
            left--;
            right--;
        }
        else{
            cout<<min(k, st[0].maxCnt)<<endl;
        }
    }
}
