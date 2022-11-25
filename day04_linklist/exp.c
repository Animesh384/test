#include<stdlib.h>
#include<stdio.h>
struct node{
    int data;
    struct node* next;
};
int main(){
    struct node* head=NULL;
    printf("%p\n",head);
    printf("%p\n",&head);
    head=(struct node*)malloc(sizeof(struct node));
    printf("%p\n",head);
    printf("%p\n",&head);
    head=(struct node*)malloc(sizeof(struct node));
    printf("%p\n",head);
    printf("%p\n",&head);

}
