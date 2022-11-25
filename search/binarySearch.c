#include <stdio.h>
#include <stdlib.h>

void binarySearch(int* arr, int s, int e, int key){

    int mid = (s+e)/2;

    if (arr[mid] == key) {
        printf("THE ELEMENT IS FOUND AT INDEX %d ",mid);
        return;
    }
    if (s >= e) {
        printf("THE ELEMENT IS NOT FOUND");
        return;
    }

    if (key < arr[mid]){
        binarySearch(arr, s, mid-1, key);
    }
    else{
        binarySearch(arr, mid+1, e, key);
    }

}

int main()
{
    int arr[5] = {5,4,3,2,1};
    int key = 3;
    //printf("THE SIZE IS %d", (sizeof(arr)/sizeof(int))-1);

    binarySearch(arr, 0, (sizeof(arr)/sizeof(int))-1, key);
    return 0;
}