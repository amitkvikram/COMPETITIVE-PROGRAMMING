#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b) for(int i = a; i<b; i++)
#define all(v) v.begin(), v.end()
#define INF 1e8

vector<pair<int,int>> pruferCodeToTree(vector<int> &pruferCode) {
    // Stores number count of nodes in the prufer code
    unordered_map<int,int> nodeCount;

    // Set of integers absent in prufer code. They are the leaves
    set<int> leaves;

    int len = pruferCode.size();
    int node = len + 2;

    // Count frequency of nodes
    for ( int i = 0; i < len; i++ ) {
        int t = pruferCode[i];
        nodeCount[t]++;
    }

    // Find the absent nodes
    for ( int i = 1; i <= node; i++ ) {
        if ( nodeCount.find ( i ) == nodeCount.end() ) leaves.insert ( i );
    }

    vector<pair<int,int>> edges;
    /*Connect Edges*/
    for ( int i = 0; i < len; i++ ){
        int a = pruferCode[i]; // First node

        //Find the smallest number which is not present in prufer code now
        int b = *leaves.begin(); // the leaf

        edges.push_back({a,b}); // Edge of the tree

        leaves.erase ( b ); // Remove from absent list
        nodeCount[a]--; // Remove from prufer code
        if ( nodeCount[a] == 0 ) leaves.insert ( a ); // If a becomes absent
    }

    // The final edge
    edges.push_back({*leaves.begin(), *leaves.rbegin()});
    return edges;
}

int main(){
    vector<int> v = {3 , 1};
    vector<pair<int, int>> edges = pruferCodeToTree(v);
    cout<<"numEdges = "<<edges.size();
}