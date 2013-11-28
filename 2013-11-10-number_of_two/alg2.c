#include <stdio.h>

int count_2s(int n)
{
    int count = 0;
    int factor = 1;
    int low = 0, cur = 0, high = 0;

    while(n/factor != 0)
    {
        low = n - (n/factor)*factor;
        high = n/(factor*10);
        cur = (n/factor) % 10;

        switch (cur) {
            case 0:
            case 1:
                count += high * factor;
                break;
            case 2:
                count += high * factor + low + 1;
                break;
            default:
                count += (high + 1) * factor;
                break;
        }
        factor *= 10;
    }
    return count;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", count_2s(n));
    return 0;
}
