﻿每个非负整数 N 都有其二进制表示。例如， 5 可以被表示为二进制 "101"，11 可以用二进制 "1011" 表示，依此类推。注意，除 N = 0 外，任何二进制表示中都不含前导零。

二进制的反码表示是将每个 1 改为 0 且每个 0 变为 1。例如，二进制数 "101" 的二进制反码为 "010"。

给你一个十进制数 N，请你返回其二进制表示的反码所对应的十进制整数。



示例 1：

输入：5
输出：2
解释：5 的二进制表示为 "101"，其二进制反码为 "010"，也就是十进制中的 2 。
示例 2：

输入：7
输出：0
解释：7 的二进制表示为 "111"，其二进制反码为 "000"，也就是十进制中的 0 。

//解题思路：使用bitCount计算N共有多少二进制位，然后再一位位地与1异或运算就行了

class Solution {
public:
	int bitwiseComplement(int N)
	{
		int one = 1;
		int bit = bitCount(N);
		for (int i = 0; i < bit; i++)
		{
			N ^= one;
			one <<= 1;
		}
		return N;
	}
	int bitCount(int n)
	{
		if (n == 0) return 1;
		int cnt = 0;
		while (n)
		{
			cnt++;
			n >>= 1;
		}
		return cnt;
	}
};
