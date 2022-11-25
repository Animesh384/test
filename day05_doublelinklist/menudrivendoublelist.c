#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* pre;
    struct node* next;
};
void createlist(struct node** head){
    int n;
    struct node* temp;
    printf("Enter the number of node:");
    temp=*head;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        if(*head==NULL){
            *head=(struct node*)malloc(sizeof(struct node));
            printf("Enter value:");
            scanf("%d",&(*head)->data);
            (*head)->next=NULL;
            (*head)->pre=NULL;
            temp=*head;
        }
        else{
            temp->next=(struct node*)malloc(sizeof(struct node));
            printf("Enter value:");
            scanf("%d",&temp->next->data);
            temp->next->pre=temp;
            temp->next->next=NULL;
            temp=temp->next;
        }
    }
}
void display(struct node* head){
    if(head==NULL){
        return;
    }
    do{
        printf("%d\n",head->data);
        head=head->next;
    }while(head!=NULL);
   /*  do{
        printf("%d\n",head->data);
        head=head->pre;
    }while(head!=NULL); */
}
void addanypoision(struct node** head){
    printf("Enter postion to insert:");
    int count=0;
    int n;
    scanf("%d",&n);
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter value:");
    scanf("%d",&temp->data);
    if(n==1){
        temp->pre=NULL;
        temp->next=*head;
        (*head)->pre=temp;
        *head=temp;
    }
    else{
        struct node* temp1=*head;
        while(temp1!=NULL){
            count++;
            if(count==n-1){
                if(temp1->next!=NULL){
                    temp->pre=temp1;
                    temp->next=temp1->next;
                    temp1->next->pre=temp;
                    temp1->next=temp;
                    break;
                }
                else{
                    temp1->next=temp;
                    temp->pre=temp1;
                    temp->next=NULL;
                    break;
                }
            }
             temp1=temp1->next;
        } 
    }
}
void delete(struct node** head){
    printf("Enter postion to delete:");
    int count=0;
    int n;
    scanf("%d",&n);
    struct node* temp=NULL;
    if(n==1){
        temp=*head;
        *head=temp->next;
        (*head)->pre=NULL;
        free(temp);
    }
    else{
        struct node* temp1=*head;
        while(temp1!=NULL){
            count++;
            if(count==n-1){
                if(temp1->next->next!=NULL){
                    temp=temp1->next;
                    temp1->next=temp1->next->next;
                    temp1->next->pre=temp1;
                    free(temp);
                }
                else{
                    temp=temp1->next;
                    temp1->next=NULL;
                    free(temp);
                }
            }
            temp1=temp1->next;
        } 
    }
}
int main(){
    int flag;
    struct node* head=NULL;
    do{
        scanf("%d",&flag);
        switch(flag){
            case 0:
            break;
            case 1:
            createlist(&head);
            break;
            case 2:
            display(head);
            break;
            case 3:
            addanypoision(&head);
            break;
            case 4:
            delete(&head);
            break;
            default:
            break;
        }
    }while(flag);
    return 0;
}