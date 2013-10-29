# LRU cache 的模拟实现

## 题目描述 
LRU (Least Recently Used) 是 cache 中一种常用的替换算法, 当访问一个地址时, 其所在的块不在cache中则未命中; 此时,如果cache为满,则需要从cache中选择一块将它换出.

cache 中常用的替换算法有: FIFO(First In First Out) 和 LRU(Least Recently Used) 等. LRU 由于其在空间时间局部性上有良好的特性, 因此使用较多.

本题就是要求用 C 语言来模拟实现 LRU 算法: 已知 cache 的大小(即cache 能容纳内存的块数), 给定可能需要访问的块总数. 写一个 LRU 算法.

## 参考资料

* http://www.cs.uml.edu/~jlu1/doc/codes/lruCache.html
* http://hawstein.com/posts/lru-cache-impl.html

