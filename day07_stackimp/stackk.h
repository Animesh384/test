#include<stdlib.h>
#include<stdio.h>
typedef struct{
    int cap;
    int *arr;
    int top;
}stack;
int isempty(stack* head){
    return head->top==-1;
}
int isfull(stack* head){
    return head->top==head->cap;
}
stack* create(int n){
    stack* head=(stack*)malloc(sizeof(stack));
    head->cap=n;
    head->arr=(int*)malloc(head->cap*sizeof(int));
    head->top=-1;
}
void push(stack* head,char data){
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
