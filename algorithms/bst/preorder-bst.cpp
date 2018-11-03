#include<iostream>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

class node{
    public:
      node *l_child = nullptr;
      node *r_child = nullptr;
      node *parent = nullptr;
      int key;
      node(int x){
          key = x;
      }
};

class bst
{
    public:
    node *root = nullptr;
    int sz = 0;
};

void print(node *r, int sz){
    if(r== nullptr)
        return;
    print(r->r_child, sz + 8);
      printf("%*s", sz, " ");
    cout << r->key << endl;
    print(r->l_child, sz + 8);
}

node* insert(node *r, int key){
    if(r== nullptr)
        return new node(key);
    if (key > r->key){
        r->r_child = insert(r->r_child, key);
    }
    else if(key < r->key){
        r->l_child = insert(r->l_child, key);
    }
    else
        return r;
}

int main(){
    bst T = bst();
    int n;
    cin >> n;
    int x;
    rep(i, 0, n){
        cin >> x;
        T.root = insert(T.root, x);
        cout << "-------------------------\n";
        print(T.root, 0);
        cout << "-------------------------\n";
    }
}