#include <stdio.h>

int count_2s(int n)
{
    int count = 0;
    int i;
    for (i=2; i<=n; i++)
    {
        int j = i;
        while(j > 0) {
            if (j%10 == 2)
                count++;
            j /= 10;
        }
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
