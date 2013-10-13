#include <stdio.h>

//该算法并不能处理所有元素均为负数的情况
//可以在处理之前对数组进行一次扫描,如果全为负数,找出最大的一个元素即可
//并不影响算法的时间复杂度 O(n)
int find_maxSubarraySum(int *arr, int size)
{
    int max_so_far = 0;      //到当前位置子数组最大和
    int max_ending_here = 0; //以当前位置元素最为最后一个元素的子数组最大和

    int i;
    for (i=0; i<size; i++)
    {
        max_ending_here += arr[i];      // ....arr[i] 最大和

        //如果 arr[i] 为负数,且抵消掉前面最大和带来的效益,那么紧接后面元素胡略前面所有的元素
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
        }
        else if (max_ending_here > max_so_far)
        {
            max_so_far = max_ending_here;
        }
    }
    return max_so_far;
}


int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    printf("Maximum contiguous subarray sum is %d\n", find_maxSubarraySum(arr, sizeof(arr)/sizeof(int)));
    return 0;

}
