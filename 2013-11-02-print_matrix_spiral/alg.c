#include <stdio.h>

#define ROW  5
#define COL  4

void print_spiral(int mat[][COL], int m, int n, int k)
{

    int i, j;

    if (m < 0 || n < 0)
        return ;
    if (m == 1)
    {
        for (j=0; j<n; j++)
            printf("%d ", mat[k][k+j]);
        return;
    }
    
    if (n == 1)
    {
        for (i=0; i<m; i++)
            printf("%d ", mat[k+i][k]);
        return ;
    }

    for (j=0; j<n-1; j++)
        printf("%d ", mat[k][k+j]);

    for (i=0; i<m-1; i++)
        printf("%d ", mat[k+i][k+n-1]);

    for (j=0; j<n-1; j++)
        printf("%d ", mat[k+m-1][k+n-1-j]);

    for (i=0; i<m-1; i++)
        printf("%d ", mat[k+m-1-i][k]);

    print_spiral(mat, m-2, n-2, k+1);
}

void print_spiral_helper(int mat[][COL], int m, int n)
{
    print_spiral(mat, m, n, 0);
}


int main()
{
    int mat[ROW][COL] = {
        {1, 2, 3, 4},
        {0, 3, 4, 1},
        {12, 3, 0, 1},
        {9, 8, 1, 3},
        {9, 89, 12, 33}
    };

    print_spiral_helper(mat, ROW, COL);

    return 0;
}
