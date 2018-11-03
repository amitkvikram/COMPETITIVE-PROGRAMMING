#include<iostream>
using namespace std;

// typedef vector<int> vi;
#define sz size()

template<class T>
class dll{
    private:
    int theSize;
    public:
    class node{
        public:
        friend class dll<T>;
        T data;
        node *next, *prev;
        node(const T &x = T{ }, node *p = nullptr, node *q = nullptr){
            data = x;
            prev = p;
            next = q;
        }
    };  

    node *Head ;
    node *Tail;

    dll(){
        theSize = 0;
        Head = new node;
        Tail = new node;
        Head->next = Tail;
        Tail->prev = Head;
    }

    ~dll(){
        // clear();
        delete Head;
        delete Tail;
    }

    int size();
    void push_back(const T &x);
    void pop_back();
    bool isEmpty();
    void erase(node *ptr);
    node *end();
    node *begin();
    void insert(node *ptr, const T &x);
    const T& back();
};

template<class T>
int dll<T>::size(){
    return theSize;
}

template<class T>
bool dll<T>::isEmpty(){
    return theSize == 0;
}

template<class T>
typename dll<T>::node* dll<T>::end(){
    return Tail;
}

template<class T>
typename dll<T>::node* dll<T>::begin(){
    return Head->next;
}

template<class T>
void dll<T>::insert(node *ptr, const T &x){
    theSize++;
    node *temp = new node{x, ptr->prev, ptr};
    ptr->prev->next = temp;
    ptr->prev = temp;
}

template<class T>
void dll<T>::erase(node *ptr){
    theSize--;
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    delete ptr; 
}

template<class T>
void dll<T>::push_back(const T &x){
    insert(end(), x);
}

template<class T>
void dll<T>::pop_back(){
    erase((end())->prev);
}

template<class T>   
const T& dll<T>::back(){
    return (end()->prev)->data;
}
///////////////////////////////////////////////////////////////////////////////////////////////
class TrieNode{
    public:
    TrieNode *children[256];
    bool isEndOfWord;
    dll<string>::node* node_ptr;
    
    TrieNode(){
        for(int i = 0; i<256; i++){
            children[i] = nullptr;
        }
        isEndOfWord = false;
        node_ptr = nullptr;
    }
};

void insert(TrieNode *nodePtr, string &s, dll<string> &mylist){
    for(int i = 0; i<s.size(); i++){
        int index = s[i] - 0;
        // cout<<index<<" ";
        if(nodePtr->children[index] == nullptr){
            nodePtr->children[index] = new TrieNode;
        }
        nodePtr = nodePtr->children[index];
    }

    // nodePtr->isEndOfWord = true;
    if(nodePtr->isEndOfWord){
       if(nodePtr->node_ptr!=nullptr) mylist.erase(nodePtr->node_ptr);
       nodePtr->node_ptr = nullptr;
    }
    else{
        nodePtr->node_ptr = mylist.end();
        mylist.insert(mylist.end(), s);
        nodePtr->isEndOfWord = true;
        nodePtr->node_ptr = nodePtr->node_ptr->prev;
    }
}

int main(){
    TrieNode root;
    string url;
    int n;
    cin>>n;
    dll<string> mylist;
    for(int i = 0; i<n; i++){
        cin>>url;
        insert(&root, url, mylist);
    }

    cout<<mylist.back()<<endl;
}

