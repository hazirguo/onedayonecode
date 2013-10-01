#include <stdio.h>
#include <string.h>

/* longest no repeat string */
int lnrs(char *str)
{
	int str_len = strlen(str);
	int i, j;
	int lnrs_len = 0;
	int dp[10000];		//dp[i] 存放的是 str[last_start] ... str[i-1] str[i] 最长子串的长度
	int last_start = 0;	
	dp[0] = 1;

	for (i=1; i<str_len; i++)
	{
		for (j=i-1; j>=last_start; j--)
		{
			if (str[i] == str[j])   //相等
			{
				dp[i] = i - j;
				last_start = j + 1;
				break;
			}
	
			if (j == last_start)
			{
				dp[i] = dp[i-1] + 1;
			}
		}
		
		if (dp[i] > lnrs_len)
			lnrs_len = dp[i];
	}

	return lnrs_len;
}

int main()
{
//	char *str = "abdffd";
//	char *str = "abba";
	char *str = "abcbdde";
	printf("%d\n", lnrs(str));
	return 0;
}
