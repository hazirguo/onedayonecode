#include <stdio.h>

int swap_bits(int x)
{
    return ((x & 0x55555555)<<1) | ((x >> 1) & 0x55555555);
}

void print_binaray(int x)
{
    char s_bits[33];
    int i;
    for (i=0; i<33; ++i, x>>= 1)
        if (x & 1)
            s_bits[31-i] = '1';
        else
            s_bits[31-i] = '0';
    s_bits[32] = '\0';
    printf("%s\n", s_bits);
}


int main()
{
    int x;
    scanf("%d", &x);
    print_binaray(x);
    print_binaray(swap_bits(x));

    return 0;
}
