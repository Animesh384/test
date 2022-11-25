#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,m;
    printf("enter a length and height:");
    scanf("%d %d",&n,&m);
    int **arr=(int**)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++){
        *(arr+i)=(int*)malloc(m*sizeof(int));
    }
    printf("enter values for array %d*%d\n",n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",(*(arr+i)+j));
        }
    }
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            for(int k=j+1;k<m;k++){
                if(arr[i][j]>arr[i][k]){
                    temp=arr[i][j];
                    arr[i][j]=arr[i][k];
                    arr[i][k]=temp;
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if(arr[j][i]<arr[k][i]){
                    temp=arr[j][i];
                    arr[j][i]=arr[k][i];
                    arr[k][i]=temp;
                }
            }
        }
    }
    printf("sorted array\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",*(*(arr+i)+j));
        }
        printf("\n");
    }

}