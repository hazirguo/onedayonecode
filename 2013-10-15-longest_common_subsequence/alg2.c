#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return a>b ? a : b;
}

int lcs(char *arr1, char *arr2, int m, int n)
{
    int L[m+1][n+1];    //L[i][j] represent for the lcs of arr1[0..i-1] & arr2[0..j-1]

    int i, j;

    for (i=0; i<=m; i++)
    {
        L[i][0] = 0;
        L[0][i] = 0;
    }
    
    //bottom up
    for (i=1; i<=m; i++)
    {
        for (j=1; j<=n; j++)
        {
            if (arr1[i] == arr2[j])
                L[i][j] = L[i-1][j-1]+1;
            else
                L[i][j] = max(L[i][j-1], L[i-1][j]);
        }
    }

    return L[m][n];
}

int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
  
    int m = strlen(X);
    int n = strlen(Y);
  
    printf("Length of LCS is %d\n", lcs( X, Y, m, n ) );
  
    return 0;
}
