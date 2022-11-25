#include<stdio.h>
#include<stdlib.h>

struct stack{
	int data;
	struct stack* link;
};

void push(struct stack** stack,int data){
	//creating new node 
	struct stack* new=(struct stack*)malloc(sizeof(struct stack));
	new->data=data;
	new->link=*stack;
	*stack=new;
}

int pop(struct stack** stack){
	struct stack* temp=*stack;
	int tempdata=(*stack)->data;
	*stack=(*stack)->link;
	free(temp);
	return tempdata;
}
int peek(struct stack** stack){
	return (*stack)->data;
}

int main(){
	struct stack* stack=NULL;
	int data;
	printf("enter a data:");
	scanf("%d",&data);
	push(&stack,data);
	printf("enter a data:");
        scanf("%d",&data);
	push(&stack,data);

	printf("\n%d pop",pop(&stack));
	printf("\n%d peek",peek(&stack));


}

