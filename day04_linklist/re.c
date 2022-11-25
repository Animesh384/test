#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
void fun(struct node*& head){
    printf("%d",head->data);
}
int main(){
    struct node* head=(struct node*)malloc(sizeof(struct node));
    head->data=7;
    fun(head);
}
