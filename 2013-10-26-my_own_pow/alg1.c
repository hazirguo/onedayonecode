#include <stdio.h>

//pow(x, n)
int power(int x, int n)
{
    if (n == 0)
        return 1;
    if (n % 2)
        return x * power(x, n/2) * power(x, n/2);
    else
        return power(x, n/2) * power(x, n/2);
}

//optimized to O(lgn)
int power1(int x, int n)
{
    if (n == 0)
        return 1;

    int tmp = power1(x, n/2);
    if (n % 2 == 0)
        return tmp*tmp;
    else
        return x*tmp*tmp;
}

//extend the pow function to work for negative n and float x
float power2(float x, int n)
{
    if (n == 0)
        return 1;

    float tmp = power(x, n/2);
    if (n % 2 == 0)
        return tmp*tmp;
    else if (n > 0)
        return x*tmp*tmp;
    else
    return tmp*tmp/x;
}

int main()
{
    int x, n;
    scanf("%d %d", &x, &n);
    printf("%d^%d = %d\n", x, n, power(x, n));
    return 0;
}
