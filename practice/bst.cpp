#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val){
        this->val = val;
    }
};

void inorder(TreeNode *curr){
    if(curr == nullptr){
        return;
    }
    inorder(curr->left);
    cout << curr->val << " ";
    inorder(curr->right);
}

void printTree(TreeNode *curr, int h){
    if(curr == nullptr)
        return;
    printTree(curr->right, h + 8);
    printf("%*s", h, " ");
    printf("%03d\n",curr->val);     //print current node's key
    printTree(curr->left, h + 8);
}

TreeNode* insertNode(TreeNode *root, int val){
    if(root == nullptr){
        return new TreeNode(val);
    }

    if(val > root->val){
        root->right = insertNode(root->right, val);
    }
    else if(val < root->val){
        root->left = insertNode(root->left, val);
    }

    return root;
}

void insertNodeIterative(TreeNode **root, int val){
    if(*root == nullptr){
        *root = new TreeNode(val);
        return;
    }

    TreeNode *curr = *root;
    while(curr!= nullptr){
        if(curr->val == val)
            break;
        if(val > curr->val){
            if(curr->right == nullptr){
                curr->right = new TreeNode(val);
                break;
            }
            curr = curr->right;
        }
        else
        {
            if(curr->left == nullptr){
                curr->left = new TreeNode(val);
                break;
            }
            curr = curr->left;
        }
    }
}

TreeNode* search(TreeNode *curr, int val){
    if(curr == nullptr)
        return nullptr;
    if(curr->val == val) return curr;
    if(val > curr->val)
        return search(curr->right, val);
    return search(curr->left, val);
}

TreeNode* searchIterative(TreeNode *curr, int val){
    while(curr!=nullptr){
        if(curr->val == val) return curr;
        if(val>curr->val) curr = curr->right;
        else
            curr = curr->left;
    }

    return nullptr;
}

TreeNode *findMin(TreeNode *curr){
    if(curr == nullptr) return nullptr;
    if(curr->left == nullptr)
        return curr;

    return findMin(curr->left);
}

TreeNode *findMax(TreeNode *curr){    
    if(curr == nullptr) return curr;
    if(curr -> right == nullptr)
        return curr;
    return findMax(curr->right);
}

//smallest in the right subtree
TreeNode *inorderSuccessor(TreeNode *root, int key){

    TreeNode *p = nullptr, *curr = root;
    while (curr != nullptr){
        if(curr->val == key)
            break;
        if(curr->val > key){
            p = curr;
            curr = curr->left;
        }else{
            curr = curr->right;
        }
    }

    if (curr->right != nullptr)
    {
        return findMin(curr->right);
    }

    return p;
}

//greatest in the left subtree
TreeNode *inorderPredecessor(TreeNode *root, int key){
    TreeNode *p = nullptr, *curr = root;
    while(curr!=nullptr){
        if(curr->val == key){
            break;
        }
        if(curr->val > key){
            curr = curr->left;
        }
        else{
            p = curr;
            curr = curr->right;
        }
    }

    if(curr->left!=nullptr){
        return findMax(curr->left);
    }

    return p;
}

TreeNode* deleteNode(TreeNode *root, int val){
    if(root == nullptr)
        return nullptr;

    if(val > root->val){
        root->right = deleteNode(root->right, val);
    }
    if(val < root->val){
        root->left = deleteNode(root->left, val);
    }
    else{
        if(root->left == nullptr){
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        if(root->right == nullptr){
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }

        TreeNode *temp = findMin(root->right);

        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }

    return root;
}

int main(){
    TreeNode *root = nullptr;
    int check = 1, val;
    do{
        if(check == 1){
            cout << "Enter val of node to be inserted: ";
            cin >> val;
            root = insertNode(root, val);
        }
        else if(check == 2){
            cout << "Enter Val of node to be deleted: ";
            cin >> val;
            root = deleteNode(root, val);
        }
        else if(check == 3){
            TreeNode *temp = findMin(root);
            if(temp == nullptr){
                cout << "Empty Tree";
            }
            else {
                cout << "Minimum Value in tree = " << temp->val;
            }
        }
        else if(check == 4){
            TreeNode *temp = findMax(root);
            if(temp == nullptr){
                cout << "Empty Tree";
            }
            else{
                cout << "Maximum value in tree = " << temp->val;
            }
        }
        else if(check == 5){
            cout << "Enter Key to be searched: ";
            cin >> val;
            TreeNode *temp = search(root, val);
            if(temp == nullptr){
                cout << "Key Not Found";
            }
            else{
                cout << "Key Found";
            }
        }
        else if(check == 6){
            cout << "Enter key of which inorder successor is required: ";
            cin >> val;
            TreeNode *temp = inorderSuccessor(root, val);
            if(temp == nullptr){
                cout << "Inorder Successor doesn't exist";
            }
            else{
                cout << "Inorder Successr of " << val << " is" << temp->val;
            }
        }
        else if(check == 7){
            cout << "Enter Key of which inorder Predecessor is required: ";
            cin >> val;
            TreeNode *temp = inorderPredecessor(root, val);
            if(temp != nullptr){
                cout << "Inorder Predecessor of " << val << " is" << temp->val;
            }
            else{
                cout << "Inorder Successor doesn't exits";
            }
        }
        else if(check == 8){
            printTree(root, 0);
        }
        else{
            break;
        }
        cout<<"\n\n1: insert\n2: delete\n3: FindMin\n4: FindMax\n5: Search\n6: InorderSuccessor\n7: InorderPredecessor\n8: PrintTree\n";
        cout << "Enter Option: ";
        cin >> check;
    } while (check >= 1 && check <= 9);
}