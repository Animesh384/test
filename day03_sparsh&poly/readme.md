# DSA (22/08/22)
## Sparse Matrix: Transpose

|row     |  col   | value |
|:------:|:------:|:-----:|
|   0    |    0   |   15  |
|   0    |    3   |   22  |
|   0    |    5   |  -15  |
|   1    |    1   |   11  |
|   1    |    2   |   3   |
|   2    |    3   |  -6   |
|   4    |    0   |   91  |
|   5    |    2   |   28  |

## sorting algorithm for 3 tuple materix
```c
int temp[3];
if(arr[i][1]*n+arr[i][0]>arr[i+1][1]*n+arr[i+1][0]){
    teemp[0]=arr[i][0];
    arr[i][0]=arr[i+1][0];
    arr[i+1][0]=temp[0];
    teemp[1]=arr[i][1];
    arr[i][1]=arr[i+1][1];
    arr[i+1][1]=temp[1];
    teemp[2]=arr[i][2];
    arr[i][2]=arr[i+1][2];
    arr[i+1][2]=temp[2];
}


for(int i=0;i<n;i++){
    temp=arr[i][0];
    arr[i][0]=arr[i][1];
    arr[i][1]=temp;
}
```



