/*  SPOJ  */
/* Problem code: CLSLDR */


#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node{
  int data;
  Node *link;
};

void insert(Node **HeadPtr, int n);
void delete(Node **HeadPtr, int pos);
void Print(Node *temp);


int main(int argc, char const *argv[]) {
  Node *Head=NULL;
  int T;
  scanf("%d",&T);
  for(int T_i=0; T_i<T; T_i++){
  int n,m,o;
  scanf("%d%d%d",&n,&m,&o);
  insert(&Head,n);
  int pos;
  ((m+(o%n))<=n) ? (pos=(m+(o%n))) : (pos=((m+(o%n))%n));
  while(n!=1){
    delete(&Head, pos);
    n--;
    if(pos==1) pos=n;
    else pos--;
    (pos+(o%n))<=n ? (pos=(pos+(o%n))) : (pos=(pos+(o%n))%n);
  }
    Print(Head);
  }


  return 0;
}

void insert(Node **HeadPtr, int n){
  Node *temp,*temp1;
  temp1= (Node*)malloc(sizeof(Node));
  temp1->data=1;
  *HeadPtr=temp1;
  temp1->link=NULL;
  temp=*HeadPtr;
  for(int i=2; i<=n; i++){
    temp1= (Node*)malloc(sizeof(Node));
    temp1->data=i;
    temp1->link=NULL;
    temp->link=temp1;
    temp=temp1;
  };

}

void delete(Node **HeadPtr, int pos){
  Node *temp=*HeadPtr;
  if(pos==1){
    *HeadPtr=(*HeadPtr)->link;
  }
  else{
    for(int i=2; i<pos; i++){
      temp=temp->link;
    }
    temp->link=temp->link->link;
  }
}

void Print(Node *temp){
  while(temp!=NULL){
    printf("%d\n",temp->data);
    temp=temp->link;
  }
}
