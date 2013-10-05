#include <stdio.h>

int aplusb(int a, int b)
{
    int sum = 0;
    int carry = 0;
    int bit_a, bit_b, bit_sum;   
    int num = 0;

    while (a || b)
    {
        bit_a = a & 1;   //取a的最低位
        bit_b = b & 1;   //取b的最低位
        bit_sum = bit_a ^ bit_b;
        if (bit_sum == 0 && bit_a == 1)    // 1 + 1
        {
            if (carry)
            {
                carry = 1;
                bit_sum = 1;
            }
            else
            {
                carry = 1;
                bit_sum = 0;
            }
        }
        else if (bit_sum == 0)    //1 0 or 0 1
        {
            bit_sum = carry;
            carry = 0;
        }
        else if (bit_sum == 1 && carry == 1)
        {
            bit_sum = 0;
            carry = 1;
        }
        else
        {
            bit_sum = 1;
            carry = 0;
        }
        sum = (bit_sum << num) + sum;
        num++;
        a >>= 1;
        b >>= 1;
    }
    sum = (carry << num) + sum;

    return sum;
}

int main()
{
    int a = 4;
    int b = 20;
    
    printf("please input a & b: ");
    scanf("%d %d", &a , &b);
    printf("a=%d, b=%d, a+b=%d\n", a, b, aplusb(a, b));

    return 0;
}
