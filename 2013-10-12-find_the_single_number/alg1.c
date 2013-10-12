#include <stdio.h>

#define SIZE_INT   32

int find_single_num(int arr[], int len)
{
    int i, j;
    int sum;
    int bit;
    int result = 0;

    //对数的每位进行相加
    for (i=0; i<SIZE_INT; i++)
    {
        sum = 0;
        bit = 1<<i;

        for (j=0; j<len; j++)
        {
            if (arr[j]&bit)
                sum++;
        }

        if (sum%3)
            result |= bit;
    }
    
    return result;
}

int main()
{
    int arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3};
    printf("The single number is %d\n", find_single_num(arr, sizeof(arr)/sizeof(int)));
    return 0;

}
