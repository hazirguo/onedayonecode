#include <stdio.h>

int calVolume(int land[], int n)
{
    int leftMax = 0;
    int rightMax = 0;
    int left = 0;
    int right = n - 1;
    int volume = 0;

    while (left < right)
    {
        if (land[left] > leftMax)
            leftMax = land[left];

        if (land[right] > rightMax)
            rightMax = land[right];

        if (leftMax >= rightMax)
        {
            volume += rightMax - land[right];
            right--;
        }
        else
        {
            volume += leftMax - land[left];
            left++;
        }
    }

    return volume;
}

int main()
{
    int arr[] = {2, 5, 1, 2, 3, 4, 7, 7, 6};

    printf("puddle of walls is %d\n", calVolume(arr, sizeof(arr)/sizeof(int)));

    return 0;
}
