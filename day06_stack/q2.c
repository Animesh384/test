#include<stdlib.h>
#include<stdio.h>
typedef struct{
    int cap;
    char *arr;
    int top;
}stack;
stack* create(int n){
    stack* head=(stack*)malloc(sizeof(stack));
    head->cap=n;
    head->arr=(char*)malloc(head->cap*sizeof(char));
    head->top=-1;
}
void push(stack* head,char data){
    if(isfull(head)){
        printf("stack overflow");
        return;
    }
    *(head->arr + ++head->top)=data;
}
char pop(stack* head){
    if(isempty(head)){
        printf("stack underflow:");
        return '\0';
    }
    return *(head->arr+head->top--);
}
char peak(stack* head){
    return head->arr[head->top];
}
int isempty(stack* head){
    return head->top==-1;
}
int isfull(stack* head){
    return head->top==head->cap;
}
int isoperand(char ch){
    if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')
        return 1;
    return 0;
}
int pre(char ch){
    switch(ch){
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return -1;
    }
}
void infiextopostfix(char* string,stack* head){
    int i=0,j=0;
    while(string[j]!='\0'){
        if(isoperand(string[j])){
            string[i]=string[j];
            j++; i++;
        }
        else if(string[j]=='('){
            push(head,string[j]);
            j++;
        }
        else if(string[j]==')'){
            j++;
            while(!isempty(head)&&peak(head)!='('){
                string[i]=pop(head);
                i++;
            }
            pop(head);
        }
        else{
            //printf("%d>=%d\n",pre(peak(head)),pre(string[j]));
            while(!isempty(head)&&pre(peak(head))>=pre(string[j])){
                printf("%c\n",string[j]);
                string[i++]=pop(head);
            }
            push(head,string[j++]);
        }
    }
    while(!isempty(head))
        string[i++]=pop(head);
    string[i]='\0';
    printf("%s\n",string);
}
int main(){
    int n;
    printf("Enter a capacity of head:");
    scanf("%d",&n);
    stack* head=create(n);
    char string[50];
    printf("Enter a string:");
    scanf("%s",string);
    infiextopostfix(string,head);

    return 0;
}
