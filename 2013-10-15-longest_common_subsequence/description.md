# 最长公共子序列 #

## 题目描述 ##
最长公共子序列(Longest Common Subsequence, LCS) 问题: 给定两个序列,找到两个序列中最长公共子序列的长度.一个序列的子序列是相对顺序是相同的,而不要求连续,如 "abc","abg","bdf", "aeg" ....等等都是 "abcdefg" 的子序列.所以一个长度为 n 的序列有 2^n 个不同的可能子序列.

最长公共子序列举例来说:

* ABCDGH 和 AEDFHR 的最长公共子序列是 "ADH",长度为3
* AGGTAB 和 GXTXAYB 的最长公共子序列是 "GTAB",长度为4

