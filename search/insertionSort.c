#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void insertionSort(int* arr, int len){
    int j, x;

    for(int i=1; i<len; i++){
        j=i-1;
        x=arr[i];

        while(j>-1 && arr[j]>x){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = x;
    }

}

int main()
{
    int arr[5] = {5,4,3,2,1};

    insertionSort(arr, (sizeof(arr)/sizeof(int)));

    for(int i=0; i<(sizeof(arr)/sizeof(int)); i++){
        printf("%d ", arr[i]);
    }
    return 0;
}