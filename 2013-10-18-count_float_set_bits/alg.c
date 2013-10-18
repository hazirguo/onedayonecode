#include <stdio.h>

//计算整数n的二进制表示中1的个数
int count_set_int(int n)
{
    int count = 0;
    
    while (n)
    {
        n &= (n-1);
        count++;
    }

    return count;
}

int cout_set_float(float num)
{
    //n 表示一个浮点型数代表几个char型数
    int n = sizeof(float) / sizeof(char);

    //取得num 的地址,让 char 型指针指向到num 位置
    char *p = (char *)(&num);

    int i;
    int count = 0;
    
    //将浮点数拆成 n 个 char 型数, 分别计算 1 的个数
    for (i=0; i<n; i++)
    {
        count += count_set_int((int)p[i]);
    }

    return count;
}

int main()
{
    float num = 0.15625;
    printf("%f's binary floating-point format has %d set bits\n", num, cout_set_float(num));
    return 0;
}
