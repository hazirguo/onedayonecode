#include <stdio.h>
#include <string.h>

int longestPalSubStr(char *str)
{
	int isPal[100][100];   // isPal[i][j] 存储的是 str[i..j] 是否为回文
	int i, j, k;
	int len = strlen(str);
	int maxlen = 1;
	
	for (i=0; i<len; i++)
		isPal[i][i] = 1;
	
	for (k=2; k<=len; k++)   //长度为 k 的子串
	{
		for (i=0; i+k<=len; i++)   // i为子串的起点
		{
			j = i+k-1;    // j 为子串的终点

			if (i+1 == j)
				isPal[i][j] = (str[i]==str[j]);
			else
				isPal[i][j] = isPal[i+1][j-1] && (str[i]==str[j]);

			if (isPal[i][j]==1 && maxlen<k)
			{
				maxlen = k;
			}
		}
	}
	return maxlen;
}

int main()
{
	char *str = "sssssssssssss";
	printf("%s longest palindrome substring length is %d\n", str, longestPalSubStr(str));
	return 0; 
}

