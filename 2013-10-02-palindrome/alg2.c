#include <stdio.h>
#include <string.h>

#define true   1
#define false  0


int ispalindrome(char *str, int s, int e)
{
    if (s == e)
        return true;
    else if (s+1 == e)
        return str[s]==str[e];
    else
        return (ispalindrome(str, s+1, e-1) && str[s]==str[e]);
}

int main()
{
    char *str = "sbs";
    if (ispalindrome(str, 0, strlen(str)-1))
        printf("%s is palindrome\n", str);
    else
        printf("%s is not palindrome\n", str);

    return 0;
}
