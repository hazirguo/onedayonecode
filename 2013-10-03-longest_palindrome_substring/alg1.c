#include <stdio.h>
#include <string.h>

int longestPalSubStr(char *str)
{
	int i, j, k;
	int len = strlen(str);
	int maxlen = 1;

	for (i=0; i<len-1; i++)
	{
		for (j=i+1; j<len; j++)
		{
			for (k=0; k<(j-i+1)/2; k++)     //判断 str[i..j] 是否为回文
			{
				if (str[i+k] != str[j-k])
					break;	
			}
			if (k >= (j-i+1)/2 && j-i+1 > maxlen)   //是回文且子串长度大于maxlen
			{
				maxlen = j-i+1;
			}
		} 
	}

	return maxlen;
}

int main()
{
	char *str = "sdfgasddsagassa";
	printf("longest palindrome substring length is %d\n", longestPalSubStr(str));
	return 0;
}
