#include <stdio.h>
#include <unistd.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void shuffle(int card[], int n)
{
    int i, j;
    for (i=0; i<n; i++)
    {
        j = rand() % (n-i) + i;      //generate a random num between i and n-1
        swap(&card[i], &card[j]);
    }
}

int main()
{
    srand(time(0));
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    shuffle(arr, 9);

    int i;
    for(i=0; i<9; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}
