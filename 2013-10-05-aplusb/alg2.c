#include <stdio.h>

int aplusb(int a, int b)
{
    if (b == 0)
        return a;

    int sum = a ^ b;             //a 和 b 二进制各位相加, 不考虑进位, 使用异或运算
    int carry = (a & b) << 1;    //a 和 b 二进制各位相加的进位情况
    aplusb(sum, carry);          //递归相加直到进位为0
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", aplusb(a, b));

    return 0;
}
