#include <stdio.h>
#include <string.h>

/* swap two char *a & *b */
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

/* reverse the string str with the length of len */
void reverse(char *str, int len)
{
    int start=0, end=len-1;
    while(start < end)
    {
        swap(&str[start], &str[end]);
        start++;
        end--;
    }
}

char *myitoa(int value, char *str, int base)
{
    int i = 0;
    int num;
    int is_negative = 0;
    if (value < 0)
    {
        value = -1*value;
        is_negative = 1;
    }

    while (value)
    {
        num = value % base;    //the per_bit number, from latter to former
        
        if (num < 10)
            str[i] = num + '0';    //0~9
        else
            str[i] = num - 10 + 'a';  //a~..

        i++;
        value /= base;
    }

    if (is_negative)   //if the value is negative, add a '-'
        str[i++] = '-';
    
    str[i] = '\0';  //don't forget!

    //reverse the string
    reverse(str, i);

    return str;
}

int main()
{
    int value = -134;
    char str[100];
    printf("%d binary is %s\n", value, myitoa(value, str, 2));
    return 0;
}
