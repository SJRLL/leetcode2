在一排座位（ seats）中，1 代表有人坐在座位上，0 代表座位上是空的。

至少有一个空座位，且至少有一人坐在座位上。

亚历克斯希望坐在一个能够使他与离他最近的人之间的距离达到最大化的座位上。

返回他到离他最近的人的最大距离。

示例 1：

输入：[1, 0, 0, 0, 1, 0, 1]
输出：2
解释：
如果亚历克斯坐在第二个空位（seats[2]）上，他到离他最近的人的距离为 2 。
如果亚历克斯坐在其它任何一个空位上，他到离他最近的人的距离为 1 。
因此，他到离他最近的人的最大距离是 2 。
示例 2：

输入：[1, 0, 0, 0]
输出：3
解释：
如果亚历克斯坐在最后一个座位上，他离最近的人有 3 个座位远。
这是可能的最大距离，所以答案是 3 。

//解题思路：
分别计算出前面、中间和后面的空位数
条件 “seats 中至少有一个 0，且至少有一个 1” 很重要

class Solution {
public:
	int maxDistToClosest(vector<int>& seats) {
		int len = seats.size(), front0 = 0, back0 = 0, max_cnt = 0, i = 0;
		for (; seats[i] == 0; i++) 
			front0++;
		int cnt = 0;
		for (; i<len; i++)
		{
			if (seats[i] == 0) cnt++;
			else
			{
				max_cnt = max(max_cnt, cnt);
				cnt = 0;
			}
		}
		max_cnt = (max_cnt + 1) / 2;
		for (i = len - 1; seats[i] == 0; i--) 
			back0++;
		return max(max(front0, back0), max_cnt);
	}
};
