#include <stdio.h>

int max_product_cutting(int n)
{
    if (n <= 1)
        return 0;
    if (n < 4)
        return n-1;

    int prod = 1;
    while (n>4)
    {
        n -= 3;
        prod *= 3;
    }

    return prod * n;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("the maximum product cutting is %d\n", max_product_cutting(n));
    return 0;
}
