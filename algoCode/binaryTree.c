#include<stdio.h>
#include "stdlib.h"

struct Node{
      int data;
      struct Node *left;
      struct Node *right;
};

typedef struct Node node;

node* getNewNode(int Data){
      node *temp= (node*)malloc(sizeof(node));
      temp->data= Data;
      temp->left= NULL;
      temp->right= NULL;
      return temp;
}

void Insert(node **rootPtr, int Data){

      if(*rootPtr==NULL){
            node *temp=getNewNode(Data);
            *rootPtr = temp;
            return;
      }

      node *tempPtr= *rootPtr;
      if(Data > tempPtr->data){
            Insert(&tempPtr->right, Data);
      }
      else{
            Insert(&tempPtr->left, Data);
      }

}

void Search(node **rootPtr, int Data){
      printf("%u\n",*rootPtr );
      if((*rootPtr)==NULL){
            printf("NOT FOUND\n");
            return;
      }
      if((*rootPtr)->data==Data){
            printf("FOUND\n");
            return;
      }

      if((*rootPtr)->data<Data){
            Search(&((*rootPtr)->right), Data);
      }

      else{
            Search(&((*rootPtr)->left), Data);
      }
}

void preOrderTraverse(node *root){
      if(root==NULL){
            return;
      }

      printf("%d ",root->data);
      preOrderTraverse(root->left);
      preOrderTraverse(root->right);
}

void postOrderTraverse(node *root){
      if(root==NULL){
            return;
      }

      postOrderTraverse(root->left);
      postOrderTraverse(root->right);
      printf("%d ",root->data);
}

void inOrderTraverse(node *root){
      if(root==NULL){
            return;
      }
      inOrderTraverse(root->left);
      printf("%d ",root->data);
      inOrderTraverse(root->right);
}

int main(){
            node *root = NULL;
            int Data;
            printf("Enter Data: ");
            scanf("%d", &Data);
            Insert(&root, Data);
            printf("Enter Data: ");
            scanf("%d", &Data);
            Insert(&root, Data);
            printf("Enter Data: ");
            scanf("%d", &Data);
            Insert(&root, Data);
            printf("Enter Data: ");
            scanf("%d", &Data);
            Insert(&root, Data);
            printf("Enter Searching Data: ");
            scanf("%d", &Data);
            Search(&root, Data);
            preOrderTraverse(root);
            postOrderTraverse(root);
            inOrderTraverse(root);

}
