#include <stdio.h>
#include <math.h>

#define ROW     4
#define COLUMN  4
#define MAXNUM  (pow(2,32)-1)

int search(int young[][COLUMN], int key)
{
    int search_row = 0;
    int search_col = COLUMN-1;
    int search_num = young[search_row][search_col];   //右上角那个数
    while (1)
    {
        search_num = young[search_row][search_col];
        if (search_num == MAXNUM)   //查找到没放数据的区域
            return 0;

        if (search_num == key)      //相等
            return 1;
        else if (search_num > key)  //比key 大,往左走
        {
            search_col--;
        } 
        else if (search_num < key)  //比key 小,往下走
        {
            search_row++;
        }

        if (search_row>=ROW || search_col<0)    //超出边界
            return 0;
    }
}

int main()
{
    int young_table[ROW][COLUMN] = {
        {1, 2, 8, 9},
        {2, 4, 9, 12},
        {4, 7, 10, 13},
        {6, 8, 11, 15}
    };

    int key;
    while (scanf("%d", &key)!=EOF)
    {
        if (search(young_table, key)==0)
            printf("cannot find the number %d\n", key);
        else
            printf("find the number %d\n", key);
    }
    return 0;
}
