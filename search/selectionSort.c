#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void selectionSort(int* arr, int len){

    int i, j, k;

    for(i=0; i<len-1; i++){
        for(j=k=i; j<len; j++){
            if (arr[j] < arr[k]){
                k=j;
            }
        }
        swap(&arr[i], &arr[k]);
    }

}

int main()
{
    int arr[5] = {5,4,3,2,1};

    selectionSort(arr, (sizeof(arr)/sizeof(int)));

    for(int i=0; i<(sizeof(arr)/sizeof(int)); i++){
        printf("%d ", arr[i]);
    }
    return 0;
}