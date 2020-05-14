给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。

说明：不要使用任何内置的库函数，如  sqrt。

示例 1：

输入：16
输出：True
示例 2：

输入：14
输出：False

//解题思路
//若num等于1或0直接返回true。若完全平方数为偶数，其开根号结果也为偶。若完全平方数为奇数，其开根号结果也为奇数。
//所以我们只需要判断num的奇偶性。接着利用循环在i∈[2, √num]中的所有奇数或偶数中找是否有i*i = num。

class Solution {
public:
	bool isPerfectSquare(int num) {

		if (num == 1 || num == 0)
		{
			return true;
		}

		long long int i;
		if (num % 2 == 0)
		{
			i = 2;
		}
		else
		{
			i = 3;
		}

		for (; i*i <= num; i += 2)
		{
			if (i*i == num)
			{
				return true;
			}
		}
		return false;

	}
};

