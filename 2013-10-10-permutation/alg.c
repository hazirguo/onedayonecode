#include <stdio.h>

void swap(char *a, char *b)
{
    char tmp;
    tmp = *b;
    *b = *a;
    *a = tmp;
}


void permutation(char *str, int pos, int len)
{
    if (pos == len)
        printf("%s\n", str);
    else
    {
        int i = pos;
        for (i=pos; i<len; i++)
        {
            swap(str+i, str+pos);
            permutation(str, pos+1, len);
            swap(str+i, str+pos);
        }
    }
}

int main()
{
    char a[] = "ABC";
    permutation(a, 0, strlen(a));
    return 0;
}
