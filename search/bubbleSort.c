#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void bubbleSort(int* arr, int len){

    for(int i=0; i<len-1; i++){
        for(int j=0; j<len-i-1; j++){
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }

}

int main()
{
    int arr[5] = {5,4,3,2,1};

    bubbleSort(arr, (sizeof(arr)/sizeof(int)));

    for(int i=0; i<(sizeof(arr)/sizeof(int)); i++){
        printf("%d ", arr[i]);
    }
    return 0;
}