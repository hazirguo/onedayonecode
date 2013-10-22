#include <stdio.h>

#define true  1
#define false 0

int is_subset_sum(int set[], int len, int sum)
{
    if (sum == 0)
        return true;
   
    if (len==0)
        return false;

    if (set[len-1] > sum)
        return is_subset_sum(set, len-1, sum);

    return is_subset_sum(set, len-1, sum) || is_subset_sum(set, len-1, sum-set[len-1]);
}


int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    if (is_subset_sum(set, sizeof(set)/sizeof(int), sum))
        printf("find a subset with given sum!\n");
    else
        printf("cannot find a subset with given sum");

    return 0;
}
