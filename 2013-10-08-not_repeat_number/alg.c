#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isReaptNum(int num)
{
    while(num != 0)
    {
        if (num%10 == (num/10)%10)
            return 1;
        num/=10;
    }
    return 0;
}


int NotReaptNum(int num)
{
    int len = log10(num);        //整数的位数
    int front_num = num / pow(10, len);   //前缀数
    int front_last_bit = front_num;       //前缀数的最后一位
    int num_bit = front_num;              //遍历到的那一位
    num = num - num_bit * pow(10, len);

    int i = len - 1;
    while (i>=0)     //从最高位逐渐往低位找前缀
    {
        num_bit = num / pow(10, i);
        front_num = front_num*10 + num_bit;
        num = num - num_bit * pow(10, i);
        if (num_bit != front_last_bit)   //不同
        {
            i--;
            front_last_bit = num_bit;
            continue;
        }
        i--;
        front_last_bit = num_bit;
        //相同, 加1直到不为重复数
        front_num++;
        while (isReaptNum(front_num))
            front_num++;
    }
    return front_num;
}


int main()
{
    int num;
    while(scanf("%d", &num)!=EOF)
        printf("%d's min not repeated number is :%d\n", num, NotReaptNum(num));
    return 0;

}
