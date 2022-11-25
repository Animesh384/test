#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
struct node* add(struct node** head,int data){
    if(*head==NULL){
        *head=(struct node*)malloc(sizeof(struct node));
        (*head)->data=data;
        (*head)->link=(struct node*)malloc(sizeof(struct node));
        (**head).link->link=NULL;
        return (*head)->link;
    }
    else{
        (*head)->data=data;
        (*head)->link=(struct node*)malloc(sizeof(struct node));
        (*head)->link->link=NULL;
        return (*head)->link;
    }
}
void display(struct node* head){
    while(head!=NULL){
        printf("%p: %d\n",head,head->data);
        head=head->link;
    }
}
int main(){
    struct node *head=NULL,*temp;
    int n,data;
    temp=add(&head,69);
    printf("enter a test case:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter a data:");
        scanf("%d",&data);
    temp=add(&temp,data);
    }
    display(head);
}
