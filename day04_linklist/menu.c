#include<stdlib.h>
#include<stdio.h>
struct node{
    int data;
    struct node* link;
};
struct node* create(){ 
    int n;
    printf("enter the number of node:");
    scanf("%d",&n);
    struct node *temp,*head;
    for(int i=0;i<n;i++){
        if(i==0){
            head=(struct node*)malloc(sizeof(struct node));
            printf("enter value:");
            scanf("%d",&head->data);
            head->link=NULL;
            temp=head;
        }
        else{
            temp->link=(struct node*)malloc(sizeof(struct node));
            printf("enter value:");
            scanf("%d",&temp->link->data);
            temp=temp->link;
            temp->link=NULL;
        }
    }
    return head;
}
void display(struct node* head){
    int count=0;
    if(head==NULL){
        printf("head is null");
    }
    else{
        while(head!=NULL){
            count++;
        printf("%d:%d\n",count,head->data);
            head=head->link;
        }
    
    }
}
struct node* addf(struct node* head){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    printf("enter a value:");
    scanf("%d",&temp->data);
    temp->link=head;
    return temp;
}
void addl(struct node* head){
    if(head==NULL){
        printf("head is null");
    }
    else{
        while(head->link!=NULL){
            //printf("%d:%d\n",count,head->data);
            head=head->link;
        }
        head->link=(struct node*)malloc(sizeof(struct node));
        printf("enter a value:");
        scanf("%d",&head->link->data);
        head->link->link=NULL;
    }
}
void del(struct node** head){
    int n,count=0;
    printf("enter a node num to delet:");
    scanf("%d",&n);
    struct node* temp;
    if(n==1){
        temp=*head;
        *head=(*head)->link;
        free(temp);
    }
    else{
        struct node* head1=*head;
        while(head1!=NULL){
            count++;
            if(count==n-1){
                if(head1->link->link!=NULL){
                temp=head1->link;
                head1->link=head1->link->link;
                free(temp);
                break;
                }
                
            }
            else{
                temp=head1->link;
                head1->link=NULL;
                free(temp);
            }
            printf("%d:%d\n",count,head1->data);
            head1=head1->link;

        }
    }
}
void inseart(struct node** head){
    int n,count=0;
    printf("enter a node num to inseart:");
    scanf("%d",&n);
    struct node* temp;
    if(n==1){
        temp=(struct node*)malloc(sizeof(struct node));
        printf("enter a value:");
        scanf("%d",&temp->data);
        temp->link=*head;
        *head=temp;  
    }
    else{
        struct node* head1=*head;
        while(head1!=NULL){
            count++;
            if(count==n-1){
                if(head1->link!=NULL){
                temp=(struct node*)malloc(sizeof(struct node));
                printf("Enter value:");
                scanf("%d",&temp->data);
                temp->link=head1->link;
                head1->link=temp;
                break;
                }
                else{
                temp=(struct node*)malloc(sizeof(struct node));
                printf("Enter value:");
                scanf("%d",&temp->data);
                head1->link=temp;
                temp->link=NULL;
            }
                
            }
            
           // printf("%d:%d\n",count,head1->data);
           head1=head1->link;
        }
    }
}
int main(){
    int flag=1;
    struct node* head=NULL;
    while(flag){
        printf("Enter 2 for creating linklist\nEnter 3 for adding in front\nEnter 4 for adding at last\nEnter 5 to delete element at any postion\nEnter 6 to insert at any position\nEnter 7 for display\nEnter 0 exit\n");
        scanf("%d",&flag);
        printf("\n");
        switch(flag){
            case 2:
                head=create();
                break;
            case 3:
                head=addf(head);
                break;
            case 4:
                addl(head);
                break;
            case 5:
                del(&head);
                break;
            case 6:
                inseart(&head);
                break;
            case 7:
                display(head);
                break;
            default:
                printf("you have entered wrong choise\n");
        }
    }
}
