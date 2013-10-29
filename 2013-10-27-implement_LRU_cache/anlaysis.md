# 算法分析 

cache 的替换算法,既要考虑到时间性能,也需要考虑空间性能.

我们设计两种数据结构:

* 双向链表: 将所有cache块进行链接, 越靠前的块表示是访问时间最近, 那么如果现在访问一个块,该块不在 cache 中, 只需要从该链表尾删除一个块, 并且将访问的块插入表头. 如果访问一个块在 cache 中, 只需要将此块从链表中的位置移到链表头.
* hash 表: 如何快速地判断访问的块是否在 cache 中,若在cache 中,在cache 的哪个位置, 这是需要考虑的. 我们设计了 hash 表, 表的大小为整个内存块的总数, hash 表的关键字为块号, 值为所在cache的地址.


## 参考资料

* http://www.cs.uml.edu/~jlu1/doc/codes/lruCache.html
* http://hawstein.com/posts/lru-cache-impl.html
