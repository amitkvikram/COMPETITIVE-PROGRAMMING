//Stack
#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node *link;
};

typedef struct Node Node;

void push(Node **topPtr, int data1);
void pop(Node **topPtr);
void isEmpty(Node *temp);
void Print(Node *temp);

int main(int argc, char const *argv[]) {
  Node *Top;
  int data1;
  printf("Enter First Element: ");
  scanf("%d",&data1);
  push(&Top,data1);

  int option;

  do{
    printf("Enter '1' for push; Enter '2' for pop; Enter '3' to Check if list is Empty: ");
    scanf("%d",&option);
    if(option==1){
      printf("Enter data: ");
      scanf("%d",&data1 );
      push(&Top,data1);
    }

    else if(option==2){
      pop(&Top);
    }

    else if(option==3){
      isEmpty(Top);
    }

  }while(option==1 || option==2|| option==3);

  return 0;
}

void push(Node **topPtr,int data1){
  Node *temp=(Node*)malloc(sizeof(Node));
  temp->link=*topPtr;
  temp->data=data1;
  *topPtr=temp;

  printf("Stack is:\n");
  Print(*topPtr);
}

void pop(Node **topPtr) {
   if(*topPtr==NULL){
     printf("No Element\n");
     return;
   }

   *topPtr=(*topPtr)->link;
   printf("Stack is:\n");
   Print(*topPtr);
}

void isEmpty(Node *temp){
  if(temp==NULL){
    printf("YES\n");
  }

  else{
    printf("NO\n" );
  }
}

void Print(Node *temp){
  if(temp==NULL){
    printf("Empty\n");
    return;
  }
  while(temp!=NULL){
    printf("%d\n",temp->data);
    temp=temp->link;
  }
}
