#include <stdio.h>

union t
{
    int i;
    char c;
};


int main()
{
    union t num;
    num.i = 1;

    printf("%p\n", &num.i);
    printf("%p\n", &num.c);
    if (num.c == 1)
        printf("Little Endian\n");
    else
        printf("Big Endian\n");

    return 0;
}
