#include "stack.h"
int main(){
    struct stack* head=createstack(100);
    char ch[100];
    scanf("%s",ch);
    int i=0;
    while(ch[i]!='\0'){
        if(ch[i]=='{'){
            push(head,ch[i]);
        }
        if(ch[i++]=='}'){
            if(peek(head)=='\0'){
            printf("not valid i");
            exit(0);
            }
            else{
                pop(head);
            }
        }
    }
    if(isempity(head)){
        printf("valid");
    }
    else{
        printf("not valid");
    }
    return 0;
}