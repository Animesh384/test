#include<stdio.h>
#include<stdlib.h>
typedef struct qnode{
	int data;
	struct qnode* next;
}qnode;
qnode* front=NULL;
qnode* rare=NULL;
void equeue(int data){
	if(!front){
		front=(qnode*)malloc(sizeof(qnode));
		rare=front;
		front->data=data;
		front->next=NULL;
	}
	else{
	      rare->next=(qnode*)malloc(sizeof(qnode));
	      rare=rare->next;
	      rare->data=data;
	      rare->next=NULL;
	}
}
int dqueue(){
	if(front){
		int data = front->data;
		printf("DATA: %d\n",front->data);
		qnode* node=front;
		free(node);
		front=front->next;
		return data;
	}
	else{
		printf("queue is Empity");
	}
}
int main(){
	equeue(5);
	dqueue();
	return 0;
}
