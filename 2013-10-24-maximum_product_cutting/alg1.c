#include <stdio.h>

int max_three_num(int a, int b, int c)
{
    a = a>b ? a : b;
    return a>c ? a : c;
}

int max_product_cutting(int n)
{
    if (n==0 || n==1)
        return 0;
    if (n==2)
        return 1;

    int i;             //the length of first segment 
    int max_val = 0;   //make a cut at different places and take the max of all
    for (i=1; i<n; i++)
        max_val = max_three_num(max_val, i*(n-i), i*max_product_cutting(n-i));

    return max_val;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("the maximum product cutting is %d\n", max_product_cutting(n));
    return 0;
}
