//question 4
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
            int flag=0;
            for(int k=i;k<n;k++){
                for(int l=0;l<m;l++){
                    if(flag==0){
                        flag=1;
                        l=j+1;
                    }
                    if(arr[i][j]==arr[k][l]&&arr[i][j]!=-1){
                        arr[k][l]=-1;
                    }
                }
            }
        }
    }
    
    printf("new array\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",*(*(arr+i)+j));
        }
        printf("\n");
    }

}
