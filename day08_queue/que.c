#include<stdio.h>
#include<stdlib.h>
typedef struct qnode{
	unsigned cap;
	unsigned size;
	int front,rare;
	int* array;
} qnode;
qnode* createqueue(int cap){
	qnode* head=(qnode*)malloc(sizeof(qnode));
	head->cap=cap;
	head->size=head->rare=head->front=0;
	head->array=(int*)malloc(head->cap*sizeof(int));
	return head;
}
int isqfull(qnode* head){
	return head->cap==head->size;
}
int isqempity(qnode* head){
	return head->size==0;
}
void eque(qnode* head){
	if(isqfull(head)) printf("queue is full\n");
	head->rare=head->rare%head->cap;
	printf("Enter a Number:");
	scanf("%d",(head->array+head->rare++));
	head->size++;
}
int dque(qnode* head){
	if(isqempity(head)) printf("queue is empity\n");
	printf("value %d\n",head->array[head->front]);
	head->size--;
	return head->array[head->front++];
}

int main(){
	int var,cap;
	qnode* head;
	do{
		printf("Enter 1 for create\nEnter 2 eque\nenter 3 for dque\nEntret 0 for exit\n ");
		scanf("%d",&var);
		switch(var){
			case 0:
				exit(0);
				break;
			case 1:
				printf("Enter a capacity:");
				scanf("%d",&cap);
				head=createqueue(cap);
				break;
			case 2:
				eque(head);
				break;
			case 3:
				dque(head);
				break;
			default:
				break;
		}
	}while(var);
	return 0;
}

