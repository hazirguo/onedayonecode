#include <stdio.h>


//求长度为n的数组arr1,arr2合并之后的中位数
int get_median(int arr1[], int arr2[], int n)
{
    int i=0, j=0;        //index of arr1,arr2
    int count=0;   
    int m1, m2;

    // ... m1 m2 ....
    while(i<n && j<n)
    {
        if (arr1[i]<arr2[j])
        {
            m1 = m2;
            m2 = arr1[i];
            i++;
        }
        else
        {
            m1 = m2;
            m2 = arr2[j];
            j++;
        }
        count++;
        if (count>n)
            break;
    }

    if (count<=n)
    {
        if (i==n)   //arr1[0..n] arr2[0..n]
        {
            m1 = arr1[n-1];
            m2 = arr2[0];
        }
        else if (j==n)  //arr12[0..n] arr1[0..n]
        {
            m1 = arr2[n-1];
            m2 = arr1[0];
        }
    }

    return (m1+m2)>>1;
}


int main()
{
    int arr1[] = {8, 9, 11, 13, 19};
    int arr2[] = {10, 11, 13, 15, 20};

    int len1 = sizeof(arr1)/sizeof(int);
    int len2 = sizeof(arr2)/sizeof(int);

    if (len1 == len2)
    {
        printf("the median of arr1 & arr2 is %d\n", get_median(arr1, arr2, len1));
    }
    else
    {
        printf("the length of two arrays is not the same!\n");
    }

    return 0;
}
