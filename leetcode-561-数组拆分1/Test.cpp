给定长度为 2n 的数组, 你的任务是将这些数分成 n 对, 例如(a1, b1), (a2, b2), ..., (an, bn) ，使得从1 到 n 的 min(ai, bi) 总和最大。

示例 1:

输入 : [1, 4, 3, 2]

输出 : 4
 解释 : n 等于 2, 最大总和为 4 = min(1, 2) + min(3, 4).

//思路：这道题有点田忌赛马的影子，这道题的关键就是谁与谁组队相比较的问题，由于求最大的值，所以我们要尽可能的保留大的值，
	  //假如按照最大 + 最小，第二大 + 第二小，就会直接把最大和第二大的数舍去了，如果最大与第二大组队就可以保留第二大的数字，
	  //以此类推，我们只需要排序之后，相邻之间组队就可以留下最大的值

class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int sum = 0;
		for (int i = 0; i<nums.size(); i += 2)
			sum += nums[i];
		return sum;
	}
};

