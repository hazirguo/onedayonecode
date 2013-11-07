#include <stdio.h>

// Flip a postive sign to negative, or a negative sign to postive
int negative(int a)
{
    int neg = 0;
    int d = a<0 ? 1 : -1;
    while(a != 0)
    {
        a += d;
        neg += d;
    }
    return neg;
}

//abstract of a
int abs(int a)
{
    return a>0 ? a : negative(a);
}

//
int different_sign(int a, int b)
{
    return ((a<0 && b>0) || (a>0 && b<0)) ? 1 : 0;
}

//substract two number a, b
int minus(int a, int b)
{
    return a + negative(b);
}


//multiply a by b
int times(int a, int b)
{
    if (a < b)
        return times(b, a);
    int sum = 0;
    int i;
    for (i=abs(b); i>0; --i)
        sum += a;
    if (b < 0)
        sum = negative(sum);
    return sum;
}


//divide a by b
int divide(int a, int b)
{
    int quotient = 0;
    int divisor = negative(abs(b));
    int divend;
    for (divend = abs(a); divend >= abs(divisor); divend += divisor)
        ++quotient;

    if (different_sign(a, b))
        quotient = negative(quotient);

    return quotient;
}



int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d-%d=%d\n", a, b, minus(a, b));
    printf("%d*%d=%d\n", a, b, times(a, b));
    printf("%d/%d=%d\n", a, b, divide(a, b));
    return 0;
}
