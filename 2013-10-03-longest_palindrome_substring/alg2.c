#include <stdio.h>
#include <string.h>

int longestPalSubStr(char *str)
{
	int i;
	int maxlen = 1;
	int high, low;
	int len = strlen(str);

	for (i=1; i<len; i++)    //以str[i] 为中心向两边扩展
	{
		//扩展的子串长度为偶数，即 ... str[i-2],str[i-1], str[i], str[i+1],...
		high = i;
		low = i-1;
		while (low>=0 && high<len && str[high]==str[low])
		{
			if (high-low+1 > maxlen)
				maxlen = high-low+1;
			high++;
			low--;
		}

		//扩展的子串长度为奇数，即 ... str[i-2],str[i-1],str[i],str[i+1],str[i+2]...
		high = i+1;
		low = i-1;
		while(low>=0 && high<len && str[high]==str[low])
		{
			if (high-low+1 > maxlen)
				maxlen = high-low+1;
			high++;
			low--;
		}
	}
	
	return maxlen;
}


int main()
{
	char *str = "sddsssfdsf";
	printf("longest palindrom substring length is %d\n", longestPalSubStr(str));
	return 0;
}
