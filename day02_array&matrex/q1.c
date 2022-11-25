#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("enter length:");
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    int *arr1=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    int temp2,temp1=arr[0];
    for(int i=0;i<n;i++){
        
        if(i==0){
            temp1=arr[i];
            arr[i]=arr[i]*arr[i+1];
        }
        else if(i==n-1){
            arr[i]=arr[i]*temp1;
        }
        else{
            temp2=arr[i];
            arr[i]=temp1*arr[i+1];
            temp1=temp2;
        } 
    }
    for(int i=0;i<n;i++){
        printf("%d ",*(arr+i));
    }
}