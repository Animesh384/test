#include"stackk.h"
int isdigitt(char ch){
    if(ch>='0'&&ch<='9') return 1;
    return 0;
}
int caltopostfix(char *string){
    printf("Enter capacity of stack:");
    int n;
    scanf("%d",&n);
    stack* head=create(n);
    n=0;
    char ob1,ob2;
    while(string[n]!='\0'){
        if(isdigitt(string[n])){
            push(head,string[n++]-'0');
        }
        else{
            ob2=pop(head);
            ob1=pop(head);
            switch(string[n++]){
                case '+':
                push(head,ob1+ob2);
                break;
                case '-':
                push(head,ob1-ob2);
                break;
                case '*':
                push(head,(ob1*ob2));
                break;
                case '/':
                push(head,(ob1/ob2));
                break;

            }
        }
    }
    return pop(head);
}
int main(){
    char exp[50];
    printf("Enter expresion:");
    scanf("%s",exp);
    printf("postfix evaluation: %d", caltopostfix(exp));
    return 0;
}
