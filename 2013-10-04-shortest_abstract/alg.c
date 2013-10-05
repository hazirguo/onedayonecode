#include <stdio.h>
#include <string.h>

#define true 1

int shortestAbstract(char *str_long, char *str_set, int *abstract_begin, int *abstract_end)
{
    int len = strlen(str_long);
    int len_set = strlen(str_set);
    int abstract_len = len + 1;   //初始摘要长度为 len+1
    int begin=0, end=0;    //滑窗的起点和终点
    
    int hash_set1[26], hash_set2[26];
    unsigned int hashmap = 0;
    int i, j;

    memset(hash_set1, 0, sizeof(hash_set1));
    memset(hash_set2, 0, sizeof(hash_set2));

    for (i=0; i<len_set; ++i)
    {
        hash_set2[str_set[i]-'a'] = 1;
        hashmap |= (1<<(str_set[i]-'a'));
    }

    while(true)
    {
        //为全部出现 且 还未遍历到头, end往右移动
        while(end<len)
        {
            if (hash_set2[str_long[end]-'a'] == 1)     //是字符集中的字符
            {
                hash_set1[str_long[end]-'a']++;    //出现次数+1
                hashmap &= ~(1<<(str_long[end]-'a'));     //

                if (hashmap == 0)
                {
                    end++;
                    break;
                }
/*
                for (i=0; i<26; i++)
                {
                    if (hash_set2[i]!=1)   //不是字符集中的字符
                        continue;
                    if (hash_set2[i]==1 && hash_set1[i]==0)   //在字符集中的字符但还没有出现   
                        break;
                }
                if (i==26)    //表示全部已经出现
                {
                    printf("OK\n");
                    end++;
                    break;
                }
                */
            }
            end++;
        }
        if (end>=len)
            break;
        //全部出现之后 
        while(true)
        {
            if (end-begin < abstract_len)
            {
                *abstract_begin = begin;
                *abstract_end = end-1;
                abstract_len = end-begin;
            }
            
            if (hash_set2[str_long[begin]-'a'] == 1)   //是字符集中的字符
            {
                hash_set1[str_long[begin]-'a']--;    //-1
                if(hash_set1[str_long[begin]-'a'] == 0)   //减为0
                {
                    hashmap |= (1<<(str_long[begin]-'a'));
                    begin++;
                    break;
                }
            }
            begin++;
        }

    }
    
    return abstract_len;
}


int main()
{
    int start, end;
    char *str = "bbbsssddagdfasgdfa";
    char *set = "afdsbig";
    int i;

    if (shortestAbstract(str, set, &start, &end) != strlen(str)+1)
    {
        printf("%s shortest abstract <%s> substring is   ", str, set);
        for (i=start; i<=end; i++)
            printf("%c", str[i]);
        printf("\n");
    }
    else
        printf("without abstract substring\n");

    return 0;
}
