#include <stdio.h>
#include <stdlib.h>
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

}
