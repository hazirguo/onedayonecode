#include <stdio.h>
#include <string.h>
#include <unistd.h>

int is_anagram(char *str1, char *str2)
{
    int n1 = strlen(str1);
    int n2 = strlen(str2);
    if (n1 != n2)
        return 0;

    int c[256];
    memset(c, 0, sizeof(c));

    int i;
    for(i=0; i<n1; i++)
    {
        ++c[(int)str1[i]];
        --c[(int)str2[i]];
    }

    for(i=0; i<256; i++)
        if (c[i] != 0)
            return 0;

    return 1;
}


int main()
{
    char str1[] = "abbcd";
    char str2[] = "abcdb";

    if (is_anagram(str1, str2))
        printf("yes!\n");
    else
        printf("no!\n");

    return 0;
}
