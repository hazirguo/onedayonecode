#include <stdio.h>

int max_three_num(int a, int b, int c)
{
    a = a>b ? a : b;
    return a>c ? a : c;
}

int max_product_cutting(int n)
{
    int prod[n+1];
    prod[0] = prod[1] = 0;

    int i;    //the length of the rope
    int j;    //the length of cutting the first segment

    // bottom up 
    for(i=2; i<=n; i++)
    {
        int max_val = 0;
        for (j=1; j<=i/2; j++)
            max_val = max_three_num(max_val, j*(i-j), j*prod[i-j]);
        prod[i] = max_val;
    }
    
    return prod[n];
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("the maximum product cutting is %d\n", max_product_cutting(n));
    return 0;    
}
