#include<stdio.h>
#include<stdlib.h>
void poly(int* arr,int n){
   printf("enter value for array:\n");
   for(int i=0;i<n;i++){
       scanf("%d",&arr[i]);
   }
   for(int i=0;i<n;i++){
       if(arr[i]==0){
           continue;
       }
       else{
          if(i==0) printf("%d+",arr[i]);    
           else printf("%dx^%d+",arr[i],i);
       }
   }
   printf("\b \n");
}
void addpoly(int* arr,int *arr1,int n,int m){
   int sum;
   if(n<=m){
       for(int i=0;i<n;i++){
          sum=arr[i]+arr1[i];
          if(i==0) printf("%d+",arr[i]); 
          else{if(sum!=0){
              printf("%dX^%d+",sum,i);
          }
          }
       }
       if(m>n){   
        for(int i=n;i<m;i++){
            if(arr1[i]!=0){
                printf("%dX^%d+",arr1[i],i);
            }
        }
       printf("\b \n");
       }
   }
   else{
    for(int i=0;i<m;i++){
          sum=arr[i]+arr1[i];
          if(i==0) printf("%d+",arr[i]); 
          else{if(sum!=0){
              printf("%dX^%d+",sum,i);
          }
          }
       }
       if(n>m){   
        for(int i=m;i<n;i++){
            if(arr1[i]!=0){
                printf("%dX^%d+",arr1[i],i);
            }
        }
       printf("\b \n");
       }
   }
   
}
int main(){
   int n,m;
   printf("enter a degree for n:");
   scanf("%d",&n);
   printf("enter a degree for m:");
   scanf("%d",&m);
   int *arr=(int *)malloc(n*sizeof(int));
   int *arr1=(int *)malloc(m*sizeof(int));
   poly(arr,n);
   poly(arr1,m);
   addpoly(arr,arr1,n,m);
   
}
