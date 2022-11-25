#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* node;
};

struct queue{
    struct node *front,*rear;
};
struct node* createnewnode(int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->node=NULL;
    return temp;
}
struct queue* createqueue(){
    struct queue* temp=(struct queue*)malloc(sizeof(struct queue));
    temp->front=temp->rear=NULL;
    return temp;
}

void enqueue(struct queue* queue,int data){
    struct node* temp=createnewnode(data);
    if(queue->rear==NULL){
        queue->front=queue->rear=temp;
        return;
    }
    queue->rear->node=temp;
    queue->rear=temp;
}
int dequeue(struct queue* queue){
    if(queue->front==NULL) return -1;
    struct node* temp=queue->front;
    queue->front=queue->front->node;
    if(queue->front==NULL){
        queue->rear=NULL;
    }
    int data=temp->data;
    free(temp);
    return data;
}


int main(){
    struct queue* queue=createqueue();
    enqueue(queue,100);
    enqueue(queue,10);
    printf("%d",dequeue(queue));
    printf("%d",dequeue(queue));
     vprintf("%d",dequeue(queue));
   

}