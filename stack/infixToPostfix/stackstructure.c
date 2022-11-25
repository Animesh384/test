#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

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
    printf("%c data has been push in stack",stack->arr[stack->top]);

}

int isempity(struct stack* stack){
     return  stack->top==-1;
}
char pop(struct stack* stack){
    if(isempity(stack)) return 0;
    printf("\n  poped %c",stack->arr[stack->top]);
    return stack->arr[stack->top--];
}
char peek(struct stack* stack){
    if(isempity(stack)) return 0;
    printf("\n%c peeeki ",stack->arr[stack->top]);
    return stack->arr[stack->top];
}
int isoperand(char ch){
    return ch>='a'&&ch<='z'||ch>='A'&&ch<='Z';
}

int prec(char ch){
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    
    default:
        return -1;
    }

}

int infixtopostfix(char *exp){
    int i,k;
    struct stack* stack=createstack(strlen(exp));
    if(!stack) return -1;

    for(i=0,k=-1;exp[i];i++){
        if(isoperand(exp[i])){
            exp[++k]=exp[i];
        }
        else if(exp[i]=='('){
            push(stack,exp[i]);
        }
        else if(exp[i]==')'){
            printf("\n%d",peek(stack)=='(');
            while(!isempity(stack)&&peek(stack)!='('){
                printf("\n hiiiih"); 
                exp[++k]=pop(stack);
            }
                pop(stack);    
        }
        else{
            if(!isempity(stack)&&prec(exp[i])<=prec(peek(stack))) exp[++k]=pop(stack);
            push(stack,exp[i]);
        }
    }
    while (!isempity(stack)) exp[++k]=pop(stack);
    exp[++k]='\0';
    printf("\nans:%s",exp);
    
}


int main(){
    char i[100];
    printf("enter a capacity of stack:");
    scanf("%s",i);
    printf("%p",i);
    infixtopostfix(i);
   /*  struct stack* stack=createstack(i);
    printf("data=");
    scanf("%d",&i);
    push(stack,i);
    printf("\ndata=");
    scanf("%d",&i);
    push(stack,i);
    printf("\n%d pop data",pop(stack));
    printf("\n%d peek",peek(stack));
 */
    return 0;
}