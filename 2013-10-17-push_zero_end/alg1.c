#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void zero_end_unorder(int *arr, int len)
{
    int i=0, j=len-1;

    while (i<j)
    {
        while(arr[i]!=0 && i<j)
            i++;

        while(arr[j]==0 && i<j)
            j--;

        swap(&arr[i], &arr[j]); 

        i++;
        j--;
    }
}

int main()
{
    int arr[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0};
    int len = sizeof(arr) / sizeof(int);

    zero_end_unorder(arr, len);

    int i;
    for (i=0; i<len; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
