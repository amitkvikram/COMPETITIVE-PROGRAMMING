#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node *prev;
  struct Node *next;
};

typedef struct Node Node;
void insert(Node **HeadPtr,int pos,int data);
void delete(Node **HeadPtr, int pos);
void Print(Node **HeadPtr);

int main() {
  Node *Head = NULL;

  int option;
  printf("Options:\nEnter '1' for insertion\nEnter 2 for deletion\n");
  scanf("%d",&option);

  while (option==1|| option==2) {
    if (option==1) {
      int pos;
      printf("Enter position of insertion: " );
      scanf("%d",&pos );
      int data;
      printf("Enter data to insert: " );
      scanf("%d",&data );
      insert(&Head, pos, data);
    }
    else{
      int pos;
      printf("Enter position of deletion: " );
      scanf("%d",&pos );
      delete(&Head, pos);
    }

    printf("Do You want to continue?\nPress '1' for insertion, Press '2' for deletion, Press '3' to exit\n");
    scanf("%d",&option );
  }
  return 0;
}

void insert(Node **HeadPtr,int pos,int data){
 Node *temp;
 temp = *HeadPtr;
 Node *temp1=(Node*)malloc(sizeof(Node));
 temp1->data=data;
 if (pos==1) {
   if(*HeadPtr)
      (*HeadPtr)->prev=temp1;
   temp1->next=*HeadPtr;
   temp1->prev=NULL;
   *HeadPtr=temp1;
 }
 else{
   for (int i=2; i<pos ;i++) {
     temp=temp->next;
   }
   temp1->next=temp->next;
   temp->next=temp1;
   temp->next->prev=temp1;
   temp1->prev=temp;

 }

 Print(HeadPtr);
}

void delete(Node **HeadPtr, int pos){
  Node *temp=*HeadPtr;
  if (pos==1) {
    *HeadPtr=(*HeadPtr)->next;
    if(*HeadPtr)
      (*HeadPtr)->prev=NULL;
  }
  else{
    printf("%u\n",temp->next->prev);
    for(int i=2;i<pos;i++){
      temp=temp->next;
    }
    temp->next->prev=temp;
    temp->next=temp->next->next;

  }
  Print(HeadPtr);
}

void Print(Node **HeadPtr){
  Node *temp=*HeadPtr;
  while(temp!=NULL){
    printf("%d\n",temp->data);
    temp=temp->next;
  }
}
