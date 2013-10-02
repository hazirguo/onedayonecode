#include <stdio.h>
#include <string.h>

#define true  1
#define false 0
int ispalindrome(char *str)
{
    int i, j, l;
    int len = strlen(str);
    int dp[100][100];           //dp[i][j]表示 str[i..j] 是否为回文

    for (i=0; i<len; i++)
        dp[i][i] = true;      //长度为1 的均是回文字串

    for (l=2; l<=len; l++)     // 长度为 l 的子串
    {
        for (i=0; i+l<=len; i++)   //判断 str[i..j] 
        {
            j = i + l - 1;
            if (i+1 == j)
                dp[i][j] = (str[i] == str[j]);
            else
                dp[i][j] = dp[i+1][j-1] && (str[i] == str[j]);
        }
    }

    return dp[0][len-1];
}

int main()
{
//    char *str = "asddfsd";
    char *str = "sdsffsds";
    if (ispalindrome(str))
    printf("%s is palindrome\n", str);
    else
        printf("%s is not palindrome\n", str);

    return 0;

}

