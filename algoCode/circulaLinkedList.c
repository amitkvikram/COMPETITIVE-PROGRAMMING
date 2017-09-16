#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node *link;
};
typedef struct Node Node;

void insert(Node **HeadPtr, int pos, int data1);
void frontPush(Node **HeadPtr, int data1);
void length(Node *temp);
void Print(Node *temp);

int main(int argc, char const *argv[]) {
  Node *Head;
  Head= NULL;

  printf("Enter First Element\n");
  int data1;
  scanf("%d", &data1 );
  printf("Ami3\n" );
  insert(&Head, 1, data1);
  Print(Head);

  int option;
  do{
    printf("Enter '1' for insertion; Enter '2' for deletion; Enter'3 for length\n");
    scanf("%d",&option );
    if(option==1){
      int data1, pos;
      printf("Enter position of insertion: ");
      scanf("%d",&pos );
      printf("Enter data to Enter\n" );
      scanf("%d",&data1 );
      printf("Ami3\n" );
      insert(&Head, pos,data1);
    }

    if(option==3){
       length(Head);
    }
    Print(Head);
  }while(option==1 || option==2 ||option==3);

  return 0;
}

void insert(Node **HeadPtr, int pos, int data1){
  Node *temp,*temp2;
  temp =*HeadPtr;
  printf("%d\n",temp );
  Node *temp1=malloc(sizeof(Node));
  temp1->data=data1;
  if(pos==1){
    if(temp!=NULL){
      while (temp->link!=*HeadPtr) {
        temp=temp->link;
      }
      temp->link=temp1;
      temp1->link=*HeadPtr;
      *HeadPtr=temp1;
    }

    else{
      *HeadPtr=temp1;
      temp1->link=*HeadPtr;
    }

  }
  else{
    for(int i=2;i<pos;i++){
      temp=temp->link;
    }
    temp1->link=temp->link;
    temp->link=temp1;
  }
}

void Print(Node *temp){
  Node *temp1=temp;
  printf("J%d\n",temp->data );
  temp=temp->link;
  while(temp!=temp1){
    printf("%d\n",temp->data);
    temp=temp->link;
  }
}

void length(Node *temp){
  int count=0;
  Node *temp1=temp;
  if(temp==NULL){
    printf("%d\n",count);
    return;
  }
  else{
    do{
      temp=temp->link;
      count++;
    }while(temp!=temp1);
    printf("%d\n",count);
  }
}
