#include<stdio.h>
#include<stdlib.h>
void fun(int* arr,int n){
   printf("enter value for a:\n");
   for(int i=0;i<n;i++){
       scanf("%d",&arr[i]);
   }
   for(int i=0;i<n;i++){
       if(arr[i]==0){
       }
       else{
          printf("%dx^%d+",arr[i],i);
       }
   }
   printf("\b \b");
}
int main(){
   int n;
   printf("enter a degree:");
   scanf("%d",&n);
   int *arr=(int *)malloc(n*sizeof(int));
   fun(arr,n);
   
}
