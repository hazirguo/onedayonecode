判断字符串是否是回文,题目本身比较简答,在线性时间就可以解决,而这里我却将该题给复杂化,重在思想.


## 算法一 ##
传统的方法,要判断 str[0..len-1] 是否是回文, 简单的做法就是从两头往中间进行比较,若遇到不等的,说明已经不满足回文的条件:

伪码如下:

    for i=0 -> len/2
        if str[i] == str[len-i-1]
            continue;
        else
            return false;
            break;
        endif
    endfor
    return true;

该算法的时间复杂度为 O(n), 空间复杂度为 O(1)


## 算法二 ##
如模拟该算法,会发现要判断 str[0..len-1] 是否为回文,其实可以转化求其子问题,判断 str[1..len-1-1] 是否为回文,再结合 str[0] 与 str[len-1] 的关系既可以知道 str[0..len-1] 是否为回文.而求 str[1..len-1-1] 是否为回文,与求 str[0..len-1] 方法相同,递归求解下去....

                          / return (isPalin(str[i+1][j-1]) && (str[i]==str[j]))
                         |
    isPalin(str[i][j]) = |  return true   if i==j
                         | 
                          \ return (str[i]==str[j])   if i+1==j


根据上面的递归方程,很容易就能写出递归的程序.


## 算法三 ##
从动态规划的角度去考虑,设P[i][j] 表示str[i..j] 是否为回文, true 表示是回文；false 表示不是回文.那么可以列出状态转移方程:   
    
                 / true    if i==j
                |
    P[i][j] =   |  (str[i]==str[j])   if i+1==j 
                |
                 \ (P[i+1][j-1] && str[i]==str[j])    if otherwise



