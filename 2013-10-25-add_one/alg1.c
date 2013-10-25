#include <stdio.h>

int add_one(int x)
{
    int m = 1;

    while(x & m)
    {
        x ^= m;
        m <<= 1;
    }

    x ^= m;
    return x;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", add_one(n));
    return 0;
}
