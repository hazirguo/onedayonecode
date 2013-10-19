#include <stdio.h>
#include <stdlib.h>

int lis(int arr[], int len)
{
    int i, j;
    int *lis_arr = (int *)malloc(len*sizeof(int));
    int lis_max;

    for(i=0; i<len; i++)
        lis_arr[i] = 1;

    for(i=1; i<len; i++)
        for(j=0; j<i; j++)
            if(arr[i]>arr[j] && lis_arr[i]<lis_arr[j]+1)
                lis_arr[i] = lis_arr[j] + 1;

    for(i=0; i<len; i++)
        if(lis_max<lis_arr[i])
            lis_max = lis_arr[i];

    free(lis_arr);
 
    return lis_max;
}

int main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int n = sizeof(arr)/sizeof(int);
    printf("Length of LIS is %d\n", lis(arr, n));
    return 0;
}
