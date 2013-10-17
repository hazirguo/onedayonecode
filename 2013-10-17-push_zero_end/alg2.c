#include <stdio.h>

void zero_end_order(int *arr, int len)
{
    int i;
    int no_zero_num = 0;

    for(i=0; i<len; i++)
        if(arr[i] != 0)
            arr[no_zero_num++] = arr[i];

    for(i=no_zero_num; i<len; i++)
        arr[i] = 0;
}

int main()
{ 
    int arr[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0};
    int len = sizeof(arr) / sizeof(int);

    zero_end_order(arr, len);

    int i;
    for (i=0; i<len; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;

}
