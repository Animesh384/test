#include<stdio.h>
#include<stdlib.h>
void display(int **ar1){
   for(int i=0;i<5;i++){
    if(i==0)printf("%d + ",ar1[i][2]);
    else printf("%dX^%d + ",ar1[i][2],ar1[i][0]*3+ar1[i][1]);
   }
}
int main(){
   int arr[3][3]={{1,0,9},{6,0,0},{8,0,9}};
   int **ar1=(int**)malloc(5*sizeof(int*));
   for(int i=0;i<5;i++){
      ar1[i]=(int*)malloc(3*sizeof(int));
   }
   int k=0;
   for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
         if(arr[i][j]!=0){
             ar1[k][0]=i;
             ar1[k][1]=j;
             ar1[k][2]=arr[i][j];
             k++;
         }
      }
   }
   display(ar1);
}
