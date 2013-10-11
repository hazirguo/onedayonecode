#include <stdio.h>

//array is sorted, len is the count of array
//we want to find three numbers a, b, c to let a+b+c = 0
void find_three_sum(int array[], int len)
{
	int i;                     //固定第一个元素a的位置
	int left, right;           //探寻第二、三个元素a/b的位置
	
	for(i=0; i<=len-3; ++i)
	{
		left = i+1;         // index of b
		right = len-1;      // index of c
		
		while (left < right)
		{
			if (array[i]+array[left]+array[right] == 0)
			{
				printf("%d+%d+%d = 0\n", array[i], array[left], array[right]);
				left++;
			}
			else if (array[i]+array[left]+array[right] > 0)
				right--;
			else 
				left++;
		}
	}
}
 
int main(void) {
		
	int array[7] = {-5, -1, 0, 2, 3, 5, 9};    //sorted!
	
	find_three_sum(array, 7);
	
	return 0;
}
