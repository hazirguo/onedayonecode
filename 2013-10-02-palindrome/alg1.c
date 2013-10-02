#include <stdio.h>
#include <string.h>

#define false 0
#define true  1

int ispalindrome(char *str)
{
    int i;
    int len = strlen(str);
    for (i=0; i<len/2; i++)
    {
        if (str[i] != str[len-1-i])
            return false;
    }
    return true;
}

int main()
{
    char str[] = "abciccba";
    if (ispalindrome(str))
        printf("%s is palindrome\n", str);
    else
        printf("%s is not palindrome\n", str);

    return 0;
}
