#include <stdio.h>

int is_subset_sum(int set[], int len, int sum)
{
    int is_sum[sum+1];    //is_sum[i] : exist a subset sum equals i?
    int i, j;
    is_sum[0] = 1;
    
    for (i=0; i<len; i++)
        is_sum[set[i]] = 1;

    for (i=0; i<len; i++)
    {
        for (j=sum-set[i]; j>=0; j--)
            if (is_sum[j] == 1)
                is_sum[j+set[i]] = 1;

        if (is_sum[sum] == 1)
            return 1;
    }

    return 0;
}

int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set)/sizeof(set[0]);
    if (is_subset_sum(set, n, sum))
       printf("Found a subset with given sum\n");
    else
       printf("No subset with given sum\n");
    return 0;
}
