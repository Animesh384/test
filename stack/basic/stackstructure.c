#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct stack{
    int top;
    unsigned cap;
    int *arr;
};

struct stack* createstack(int cap){
    struct stack* stack=(struct stack*)malloc(sizeof(struct stack));
    stack->cap=cap;
    stack->top=-1;
    stack->arr=(int*)malloc(stack->cap*sizeof(int));
    return stack;
}
int isfull(struct stack* stack){
    return stack->top==stack->cap-1;
}

void push(struct stack* stack,int data){
    if(isfull(stack)) return;
    /* arr store some location in heap eg 10003
    int *array=stack->arr eg 10003
    *(array+(1+stack->top))=data
    *(stack->arr+(++stack->top))=data; */
    stack->arr[++stack->top]=data;
    printf("%d data has been push in stack",data);

}

int isempity(struct stack* stack){
     return  stack->top==-1;
}
int pop(struct stack* stack){
    if(isempity(stack)) return 0;
    return stack->arr[stack->top--];
}
int peek(struct stack* stack){
    if(isempity(stack)) return 0;
    return *stack->arr;
}
int main(){
    int i;
    printf("enter a capacity of stack:");
    scanf("%d",&i);
    struct stack* stack=createstack(i);
    printf("data=");
    scanf("%d",&i);
    push(stack,i);
    printf("\ndata=");
    scanf("%d",&i);
    push(stack,i);
    printf("\n%d pop data",pop(stack));
    printf("\n%d peek",peek(stack));

    return 0;
}