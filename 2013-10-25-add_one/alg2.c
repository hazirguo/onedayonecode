#include <stdio.h>

int add_one(int n)
{
    //-n = ~n + 1
    //-(n+1) = ~n
    //n+1 = -(~n)
    return -1 * (~n);
}

int main()
{
    int num;
    scanf("%d", &num);
    printf("%d + 1 = %d\n", num, add_one(num));
    return 0;
}
