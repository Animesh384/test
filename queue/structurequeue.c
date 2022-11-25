#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int front, rear, size;
    unsigned capacity;
    int *array;
};\
int isfull(struct queue *queue)
{
    return queue->capacity==queue->size;
}
int isempty(struct queue *queue)
{
    return queue->size==0;
}
struct queue *createqueue(unsigned capacity)
{
    struct queue *queue = (struct queue *)malloc(sizeof(struct queue));
    queue->capacity = capacity;
    queue->size = 0;
    queue->front = 0;
    queue->rear = queue->capacity - 1;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}
int enqueue(struct queue *queue, int data){
    if (isfull(queue))
        return 0;
    /* if((queue->front+1)==queue->rear||(queue->rear+1)==queue->front)
    return 0;  */   
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = data;
    queue->size++;
    return 1;
}
int dequeue(struct queue* queue){
    int data;
    if(isempty(queue)) return -666699999;
    data=queue->array[queue->front];
    queue->front=(queue->front+1)%queue->capacity;
    queue->size--;
    return data;
}


int main()
{
    struct queue* queue=createqueue(5);
    printf("%d",enqueue(queue,10));
    printf("\n%d",enqueue(queue,111));
    printf("\n%d",dequeue(queue));
    printf("\n%d",dequeue(queue));
    printf("\n%d",dequeue(queue));

    return 0;
}