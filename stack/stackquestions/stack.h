#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct stack{
    int top;
    unsigned cap;
    char *arr;
};

struct stack* createstack(int cap){
    struct stack* stack=(struct stack*)malloc(sizeof(struct stack));
    stack->cap=cap;
    stack->top=-1;
    stack->arr=(char*)malloc(stack->cap*sizeof(char));
    return stack;
}
int isfull(struct stack* stack){
    return stack->top==stack->cap-1;
}

void push(struct stack* stack,char data){
    if(isfull(stack)) return;
    /* arr store some location in heap eg 10003
    int *array=stack->arr eg 10003
    *(array+(1+stack->top))=data
    *(stack->arr+(++stack->top))=data; */
    stack->arr[++stack->top]=data;
    //printf("%d data has been push in stack",data);

}

int isempity(struct stack* stack){
     return  stack->top==-1;
}
char pop(struct stack* stack){
    if(isempity(stack)) return 0;
    return stack->arr[stack->top--];
}
char peek(struct stack* stack){
    if(isempity(stack)) return '\0';
    return *stack->arr;
}