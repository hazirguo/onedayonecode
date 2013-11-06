#include <stdio.h>

void show_mem(char *start, int n)
{
    int i;
    for (i=0; i<n; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}


int main()
{
    unsigned int i = 0x01234567;
    show_mem((char *)&i, 4);
    char *c = (char *)&i;
    if (*c == 1)
        printf("Big Endian\n");
    else
        printf("Little Endian\n");

    return 0;
}
