#include <stdio.h>
#include <math.h>

#define ROW 4
#define COL 5

#define INT_MIN  -1*pow(2,32)

int kadane(int *arr, int *start, int *end, int n)
{
    int currSum = 0;
    int maxSum = INT_MIN;
    int i;
    
    int currStart = 0;
    *end = -1;

    for (i=0; i<n; i++)
    {
        currSum += arr[i];
        if (currSum < 0)
        {
            currSum = 0;
            currStart = i+1;
        }
        else if (currSum > maxSum)
        {
            maxSum = currSum;
            *start = currStart;
            *end = i;
        }
    }

    if (*end != -1)
        return maxSum;

    maxSum = arr[0];
    *start = *end = 0;

    for (i=1; i<n; i++)
    {
        if (arr[i] > maxSum)
        {
            maxSum = arr[i];
            *start = *end = i;
        }
    }
    return maxSum;
}


void findMaxSum(int M[][COL])
{
    int maxSum = INT_MIN;
    int finalLeft, finalRight, finalTop, finalBottom;

    int left, right, i;
    int temp[ROW], sum ,start, end;

    for (left=0; left<COL; ++left)
    {
        memset(temp, 0, sizeof(temp));

        for (right=left; right<COL; ++right)
        {
            for (i=0; i<ROW; ++i)
            {
                temp[i] += M[i][right];
            }

            sum = kadane(temp, &start, &end, ROW);

            if (sum > maxSum)
            {
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = end;
            }
        }
    }

    printf("(Top, Left) (%d, %d)\n", finalTop, finalLeft);
    printf("(Bottom, Right) (%d, %d)\n", finalBottom, finalRight);
    printf("max sum is %d\n", maxSum);
}

int main()
{
    int M[ROW][COL] = {{1, 2, -1, -4, -20},
                       {-8, -3, 4, 2, 1},
                       {3, 8, 10, 1, 3},
                       {-4, -1, 1, 7, -6}
                      };
 
    findMaxSum(M);
 
    return 0;
}
