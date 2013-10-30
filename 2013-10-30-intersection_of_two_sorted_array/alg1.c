#include <stdio.h>

void intersect(int arr1[], int arr2[], int m, int n)
{
    int i=0, j=0;
    while(i<m && j<n)
    {
        if (arr1[i] > arr2[j])
            j++;
        else if (arr1[i] < arr2[j])
            i++;
        else
        {
            printf("%d ", arr1[i]);
            i++;
            j++;
        }
    }
    printf("\n");
}

int main()
{
    int arr1[] = {1, 3, 5, 6, 10, 21};
    int arr2[] = {2, 3, 5, 9, 21, 24, 55};

    int m = sizeof(arr1) / sizeof(int);
    int n = sizeof(arr2) / sizeof(int);

    intersect(arr1, arr2, m, n);

    return 0;
}
