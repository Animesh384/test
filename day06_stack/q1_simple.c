#include<stdlib.h>
#include<stdio.h>
typedef struct{
    int cap;
    int *arr;
    int top;
}stack;
stack* create(int n){
    stack* head=(stack*)malloc(sizeof(stack));
    head->cap=n;
    head->arr=(int*)malloc(head->cap*sizeof(int));
    head->top=-1;
}
void push(stack* head,int data){
    if(isfull(head)){
        printf("stack overflow");
        return;
    }
    *(head->arr + ++head->top)=data;
}
int pop(stack* head){
    if(isempty(head)){
        printf("stack underflow:");
        return 5505;
    }
    return *(head->arr+head->top--);
}
int isempty(stack* head){
    return head->top==-1;
}
int isfull(stack* head){
    return head->top==head->cap;
}

int main(){
    int n;
    printf("Enter a capacity of head:");
    scanf("%d",&n);
    stack* head=create(n);
    printf("enter a data to push:");
    scanf("%d",&n);
    do{
        push(head,n);
        printf("Enter 0 for exit\nEnter data to entter in stack\n");
        scanf("%d",&n);
    }while(n);
    while(head->top>-1){
        printf("%d\n",pop(head));
    }
    return 0;
}
