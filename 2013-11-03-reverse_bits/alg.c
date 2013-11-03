#include <stdio.h>

typedef unsigned int uint;

//swap x's ith bit and jth bit
uint swap_bits(uint x, uint i, uint j)
{
    uint bit_i = (x >> i) & 1;
    uint bit_j = (x >> j) & 1;
    
    //not the same
    if (bit_i ^ bit_j)
    {
        x ^= ((1U << i) | (1U << j));
    }

    return x;
}

//reverse x binary bits
uint reverse_xor(uint x)
{
    uint n = sizeof(x) * 8;
    uint i;
    for (i=0; i<n/2; i++)
        x = swap_bits(x, i, n-i-1);

    return x;
}

//print x binary bits
void print_binary(uint x)
{
    int n = sizeof(x) * 8;
    int i;
    for (i=n-1; i>=0; i--)
        if ( (x >> i) & 1 )
            printf("1");
        else
            printf("0");
    printf("\n");
}

int main()
{
    uint x;
    scanf("%u", &x);
    print_binary(x);
    print_binary(reverse_xor(x));
    return 0;
}
