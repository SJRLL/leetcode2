给定一个没有重复数字的序列，返回其所有可能的全排列。

示例 :

输入 : [1, 2, 3]
输出 :
   [
	   [1, 2, 3],
	   [1, 3, 2],
	   [2, 1, 3],
	   [2, 3, 1],
	   [3, 1, 2],
	   [3, 2, 1]
   ]

//解题思路：
	 对于当前数nums[k], 它前面的所有数顺序固定，
	它后面的数已排好（perm(k + 1)）, 只需要让它与后面的数逐个交换就可以得到perm（k），即k和k后面的数的全排列；
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums)
	{
		vector<vector<int>> res;
		int k = 0, m = nums.size() - 1;
		prem(nums, k, m, res);
		return res;
	}
	void swap(int& a, int& b)
	{
		int temp;
		temp = a;
		a = b;
		b = temp;
	}
	void prem(vector<int>& nums, int k, int m, vector<vector<int>>& vv)
	{
		if (k == m)
		{
			vv.push_back(nums);
		}
		for (int i = k; i <= m; ++i)
		{
			swap(nums[i], nums[k]);
			prem(nums, k + 1, m, vv);
			swap(nums[i], nums[k]);
		}
	}
};