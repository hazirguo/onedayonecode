#include <stdio.h>
#include <math.h>

int is_perfect_square_num(int num)
{
    int s = sqrt(num);
    if (s*s == num)
        return 1;
    return 0;

}

int is_fibonacci_num(int num)
{
    return is_perfect_square_num(5*num*num+4) ||
            is_perfect_square_num(5*num*num-4);
}

int main()
{
    int num;
    scanf("%d", &num);
    if (is_fibonacci_num(num))
        printf("%d is fibonacci number!\n", num);
    else
        printf("%d is not fibonacci number!\n", num);

    return 0;
}
