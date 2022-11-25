#include <stdio.h>
#include <stdlib.h>

int arr[9] = {-1, -1, -1. -1, -1, -1, -1. -1, -1};

void insert(int value){
    int key = value%9;

    if (arr[key] != -1){
        arr[key] = value;
    }

    else{
        printf("COLLISION");
    }
}

void search(int value){
    int key = value%9;

    if (arr[key] == value){
        printf("THE ELEMENT IS PRESENT\n");
    }
    else{
        printf("THE ELEMENT IS NOT PRESENT\n");
    }
}

int main()
{
    insert(5);
    insert(52);
    insert(87);
    insert(52);
    insert(6);

    search(87);
    search(4);

    for(int i=0; i<9; i++){
        printf("%d\n", arr[i]);
    }
    return 0;
}