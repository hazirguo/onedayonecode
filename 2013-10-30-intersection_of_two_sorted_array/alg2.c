#include <stdio.h>

void intersect(int arr1[], int arr2[], int m, int n)
{
    int i = 0;
    int l, r, mid;

    for (i=0; i<m; i++)
    {
        l = 0; r = n-1;
        while (l<=r)
        {
            mid = l + (r-l)/2;  //(l+r)/2
            if (arr1[i] > arr2[mid])
                l = mid + 1;
            else if (arr1[i] < arr2[mid])
                r = mid - 1;
            else
            {
                printf("%d ", arr1[i]);
                break;
            }
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
