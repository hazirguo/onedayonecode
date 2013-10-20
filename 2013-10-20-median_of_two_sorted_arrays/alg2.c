#include <stdio.h>

int max(int a, int b)
{
    return a>b ? a : b;
}

int min(int a, int b)
{
    return a<b ? a : b;
}

int median(int arr[], int n)
{
    if (n%2)   //odd
        return arr[n/2];
    else
        return (arr[n/2-1]+arr[n/2])>>1;
}

int get_median(int arr1[], int arr2[], int n)
{
    if (n == 1)
        return (arr1[0]+arr2[0])>>1;

    if (n == 2)
        return (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1]))>>1;

    int mid1 = median(arr1, n);
    int mid2 = median(arr2, n);

//    printf("%d %d\n", mid1, mid2);

    if (mid1 == mid2)
        return mid1;

    if (mid1 > mid2)
    {
        if (n%2)   //odd
            return get_median(&arr1[0], &arr2[n/2+1], n/2);
        else
            return get_median(&arr1[0], &arr2[n/2], n/2);
    }
    else
    {
        if (n%2)  //odd
            return get_median(&arr1[n/2+1], &arr2[0], n/2);
        else      //even       
            return get_median(&arr1[n/2], &arr2[0], n/2);
    }
}


int main()
{
    int arr1[] = {9, 11, 13, 20, 22, 40};
    int arr2[] = {13, 15, 20, 21, 23, 50};

    int len1 = sizeof(arr1)/sizeof(int);
    int len2 = sizeof(arr2)/sizeof(int);

    if (len1 == len2)
    {
        printf("the median of arr1 & arr2 is %d\n", get_median(arr1, arr2, len1));
    }
    else
    {
        printf("the length of two arrays is not the same!\n");
    }

    return 0;  
}
