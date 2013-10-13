#include <stdio.h>

inline int max(int a, int b)
{
    return a>b ? a : b;
}

int findMaxSubarraySum(int arr[], int size)
{
    int max_so_far = arr[0];      //到目前为止子数组最大之和
    int curr_max = arr[0];        //当前最大和

    int i;
    for (i=1; i<size; i++)
    {
        curr_max = max(arr[i], curr_max+arr[i]);
        if (curr_max > max_so_far)
            max_so_far = curr_max;
    }

    return max_so_far;
}

int main()
{
    int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = findMaxSubarraySum(a, n);
    printf("Maximum contiguous sum is %d\n", max_sum);
    return 0;
}
