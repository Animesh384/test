#include <stdio.h>
#include <stdlib.h>
int** sumpoly(int **arr,int count,int **arr1,int count1){
    int** result=(int**)malloc((count+count1)*sizeof(int*));
    for(int i=0;i<count+count1;i++){
        *(result+i)=(int*)malloc(3*sizeof(int));
    }
    int apos=1,bpos=1;
    int k=1;
    result[0][0]=0;
    while(apos<count&&bpos<count1){
        if(arr[apos][0]>arr1[bpos][0]||arr[apos][0]==arr1[bpos][0]&&arr[apos][1]>arr1[bpos][1]){
            result[k][0]=arr1[bpos][0];
            result[k][1]=arr1[bpos][1];
            result[k][2]=arr1[bpos][2];
            k++;
            bpos++;
        }
        else if(arr[apos][0]<arr1[bpos][0]||arr[apos][0]==arr1[bpos][0]&&arr[apos][1]<arr1[bpos][1]){
            result[k][0]=arr[apos][0];
            result[k][1]=arr[apos][1];
            result[k][2]=arr[apos][2];
            k++;
            apos++;
        }
        else{
            result[k][0]=arr[apos][0];
            result[k][1]=arr[apos][1];
            result[k][2]=arr[apos][2]+arr1[bpos][2];
            k++;
            apos++;
            bpos++;
        }
    }
    while(apos<count){
            result[k][0]=arr[apos][0];
            result[k][1]=arr[apos][1];
            result[k][2]=arr[apos][2];
            k++;
            apos++;
        }
        while(bpos<count1){
            result[k][0]=arr1[bpos][0];
            result[k][1]=arr1[bpos][1];
            result[k][2]=arr1[bpos][2];
            k++;
            apos++;
        }
        result[0][0]=k;
        return result;
}
void tuple_3(int** arr, int n, int m, int** tupel, int count){
    int temp=1;
    tupel[0][0]=n;
    tupel[0][1]=m;
    tupel[0][2]=count-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]!=0){
                tupel[temp][0]=i;
                tupel[temp][1]=j;
                tupel[temp][2]=arr[i][j];
                temp++;
            }
        }
    }
    for(int i=0;i<count;i++){
        if(i==0) printf("row\tcol\tval\n");
        for(int j=0;j<3;j++){
            printf("%d\t",*(*(tupel+i)+j));
        }
        printf("\n");
    }
}
int main(){
    int n=0;
    printf("Enter the size of row: ");
    scanf("%d", &n);

    int m=0;
    printf("Enter the size of columns: ");
    scanf("%d", &m);

    int count=0;
    int** arr=(int**)malloc(n * sizeof(int*));
    for(int i=0;i<n;i++){
        arr[i]=(int*) malloc(m * sizeof(int));
        for(int j=0;j<m;j++){
                    scanf("%d", &arr[i][j]);
                    if(arr[i][j]!=0){
                        count++;
                    }
        }
    }
    count++;
    int** tuple=(int**)malloc(count*sizeof(int*));
    for(int i=0;i<count;i++){
        tuple[i]=(int*)malloc(3*sizeof(int));
    }

    tuple_3(arr, n, m, tuple, count);
    int n1=0;
    printf("Enter the size of row: ");
    scanf("%d", &n1);
    
    int m1=0;
    printf("Enter the size of columns: ");
    scanf("%d", &m1);

    int count1=0;
    int** arr1=(int**)malloc(n1 * sizeof(int*));
    for(int i=0;i<n1;i++){
    arr1[i]=(int*) malloc(m1 * sizeof(int));
        for(int j=0;j<m1;j++){
            scanf("%d", &arr1[i][j]);
            if(arr1[i][j]!=0){
                count1++;
            }
        }
    }
    count1++;
    int** tuple1=(int**)malloc(count1*sizeof(int*));
    for(int i=0;i<count1;i++){
        tuple1[i]=(int*)malloc(3*sizeof(int));
    }

    tuple_3(arr1,n1,m1,tuple1,count1);
    int **result=sumpoly(tuple,count,tuple1,count1);
    printf("\n----------------\n");
    for(int i=1;i<result[0][0];i++){
        if(i==1) printf("row\tcol\tval\n");
        for(int j=0;j<3;j++){
            printf("%d\t",*(*(result+i)+j));
        }
        printf("\n");
    }
}
