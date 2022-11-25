#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void insertionSort(int* arr, int len){

    int idx, ele;

    for(int i=1; i<len; i++){
        ele = arr[i];

        for(int j=i-1; j>-1; j--){
            if (arr[j] > ele){
                arr[j+1] = arr[j];
            }
            else{
                idx = j;
                break;
            }
        }
        arr[idx+1] = ele;

    }

}

int main()
{
    int arr[5] = {5,4,3,2,1};

    insertionSort(arr, (sizeof(arr)/sizeof(int)));

    for(int i=0; i<(sizeof(arr)/sizeof(int)); i++){
        printf("%d Hello", arr[i]);
    }
    return 0;
}