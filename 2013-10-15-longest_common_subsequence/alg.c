#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return a>b?a:b;
}

int lcs(char *arr1, char *arr2, int m, int n)
{
    //if either string's length is zero, then the recursive exit 
    if (m==0 || n==0)
        return 0;
    
    //if the last letter of arr1 equals the last letter of arr2
    if (arr1[m-1] == arr2[n-1])
        return 1 + lcs(arr1, arr2, m-1, m-1);
    else  //not equals
        return max(lcs(arr1, arr2, m-1, n), lcs(arr1, arr2, m, n-1));
}

int main()
{
    char arr1[] = "AGGTAB";
    char arr2[] = "GXTXYAB";

    printf("length of lcs is %d\n", lcs(arr1, arr2, strlen(arr1), strlen(arr2)));
    
    return 0;
}
