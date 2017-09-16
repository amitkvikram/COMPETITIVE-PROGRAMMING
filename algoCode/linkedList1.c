//Singly Linked list

#include <stdio.h>
#include <stdlib.h>
typedef  struct Node Node;
struct Node{
  int data;
  Node *link;
};


void insert(Node **HeadPtr,int position, int data);
void Print(Node **Headptr);
int size(Node *temp);
void printRecursion(Node *temp);
void printReverse(Node *temp);
void delete(Node **Headptr, int pos);
void pop(Node **HeadPtr);   //Different from stack, here time Complexity is O(n), bcoz last element will be deleted...in stack time Complexity is O(1);
void push(Node **HeadPtr, int data);
void reverse(Node **HeadPtr);

int main() {
  Node *Head;  //head pointer
  Head=NULL;   //Head pointer sets to NULL in starting

  int option;

  printf("Options:\nInsertion:Enter '1';\nDeletion:Enter '2'\nreversion:Enter '3'\n");
  scanf("%d",&option);

  while(option==1 || option==2 || option==3 ||option==4 ||option==5 ||option==6){
    if(option==1){
      int pos;
      printf("Enter Position of insertion");
      scanf("%d",&pos);
      int tempData;
      printf("Enter data to Enter");
      scanf("%d",&tempData);
      insert(&Head,pos,tempData); //passing Head Pointer, Position where to enter element, and what to enter;
    }
    else if(option==2){
      int pos;
      printf("Enter Position of Deletion");
      scanf("%d",&pos);
      delete(&Head,pos);
    }
    else if(option==3){
      printf("Revrsed List is:\n" );
      reverse(&Head);
    }

    else if(option==4){
      printf("Reversed Print is:\n" );
      printReverse(Head);
    }

    else if(option==5){
      pop(&Head);
    }

    else{
      int data1;
      printf("Enter data: ");
      scanf("%d", &data1);
      push(&Head,data1);
    }

    printf("Do u Want to continue: Press '1' for Insertion; Press '2' for Deletion; Press '3' for Reversing the list; Press '4' to print in Reverse Order");
    printf("; Press '5' to pop; Press '6' to push; Press '7' to Exit:\n");
    scanf("%d",&option);
  }

  return 0;
}

void insert(Node **HeadPtr, int pos, int data){

      if(size(*HeadPtr)+1<pos){
      printf("index out of range\n");
      return;
    }
    Node *temp,*temp1,*temp2;
    temp=(Node*)malloc(sizeof(Node));  //Dynamically Allocating Memory
    temp->data=data;
    temp1=*HeadPtr;
    if(pos==1){
      temp->link=*HeadPtr;
      *HeadPtr=temp;
    }
    else{
      for(int i=2;i<pos;i++){
        temp1=temp1->link;
      }
      temp2=temp1->link;
      temp->link=temp2;
      temp1->link=temp;

    }
    printRecursion(*HeadPtr);

}

void delete(Node **Headptr, int pos){
  Node *temp1;
  temp1=*Headptr;

  if(size(*Headptr)==0){
  printf("List is already empty\n");
  return;
  }
  else if(size(*Headptr)<pos){
    printf("index Out Of Range\n");
    return;
  }

  if(pos==1){
    *Headptr=(*Headptr)->link;
  }
  else{
    for(int i=2;i<pos;i++){
      temp1=temp1->link;
    }
    temp1->link=temp1->link->link;
  }
  Print(Headptr);
}

void reverse(Node **HeadPtr){
  Node *temp=*HeadPtr;
  Node *prev=NULL;
  Node *temp1;
  while(temp!= NULL){
    temp1=temp->link;
    temp->link=prev;
    prev=temp;
    temp=temp1;
  }
  *HeadPtr = prev;


 

  printf("ab\n");
  Print(HeadPtr);
}

void Print(Node **Headptr){
  Node *temp;
  temp=*Headptr;
  while(temp!=NULL){
   printf("%d\n",temp->data );
   temp=temp->link;
  }
}

void printRecursion(Node *temp){
  if(temp==NULL) return;
  printf("%d\n",temp->data );
  printRecursion(temp->link);

 }

void printReverse(Node *temp){
  if(temp==NULL) return;
  printReverse(temp->link);
  printf("%d\n",temp->data );
 }

int size(Node *temp){
  int count=0;
  while(temp!=NULL){
    temp=temp->link;
    count++;
  }

  return count;
}

void pop(Node **HeadPtr){
  Node *temp=*HeadPtr;
  if(temp->link==NULL) *HeadPtr=NULL;
  else{
    while(temp->link->link!=NULL){
       temp=temp->link;
    }

    temp->link=NULL;
  }
  Print(HeadPtr);
}

void push(Node **HeadPtr, int data1){
  Node *temp=*HeadPtr;
  Node *temp1=(Node*)malloc(sizeof(Node));
  if(temp1==NULL) printf("Error in Allocating Memory\n");
  temp1->data=data1;
  temp1->link=NULL;
  if(temp==NULL){
    *HeadPtr=temp1;
  }
  else{
    while(temp->link!=NULL){
      temp=temp->link;
    }
    temp->link=temp1;
  }

}
