#include <stdio.h>
#include <math.h>

//对数取 log2, 判断结果是否为整数
int is_power_of_two1(int n)
{
    float num = log2(n);
    if ((int)(num*100)%100 == 0)
        return 1;
    return 0;
}

//能否一直被2整除
int is_power_of_two2(int n)
{
    if (n == 0)
        return 0;
    while (n != 1)
    {
        if (n%2 != 0)
            return 0;
        n /= 2;
    }
    return 1;
}

//二进制表示一定只有一个1
int is_power_of_two3(int n)
{
    int count_one = 0;
    while(n)
    {
        n &= (n-1);
        count_one++;
    }

    if (count_one == 1)
        return 1;
    return 0;
}

//2的指数,那么 n&(n-1) 为0,取非之后为1; 而且n!=0
int is_power_of_two4(int n)
{
    return n && (!(n&(n-1)));
}

void test(int n)
{
    int result1, result2, result3, result4;
    result1 = is_power_of_two1(n);
    result2 = is_power_of_two2(n);
    result3 = is_power_of_two3(n);
    result4 = is_power_of_two4(n);

    if (result1==result2 && result1==result3 && result1==result4)
        if(result1 == 1)
            printf("%d is power of two!\n", n);
        else
            printf("%d isnot power of two!\n", n);
    else
        printf("there is problem of some alg\n");
}

int main()
{
    int n = 23;
    test(n);
    
    n = 1024;
    test(n);

    n = 18;
    test(n);

    n = 16;
    test(n);

    return 0;
}


