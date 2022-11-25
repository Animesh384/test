#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,k;
    int temp1;
    printf("enter a number :");
    scanf("%d",&n);
    printf("enter a value for n array\n");
    int *arr=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                temp1=arr[j];
                arr[j]=arr[i];
                arr[i]=temp1;
            }
        }
    }
    printf("enter a number kth element:");
    scanf("%d",&k);
    printf("kth small element :%d kth largest elementL: %d",arr[k-1],arr[n-k]);

}