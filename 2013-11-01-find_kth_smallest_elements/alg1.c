#include <stdio.h>

int find_kth_smallest(int A[], int B[], int m, int n, int k)
{
    int i = 0;
    int j = 0;
    int count = 0;

    while (i<m && j<m)
    {
        if (A[i] > B[j])
        {
            count++;
            if (count == k)
                return A[i];
            j++;
        }
        else
        {
            count++;
            if (count == k)
                return B[j];
            i++;
        }
    }
}

int main()
{

}
