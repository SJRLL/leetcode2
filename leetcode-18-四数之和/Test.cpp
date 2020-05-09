给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
	[-1, 0, 0, 1],
	[-2, -1, 1, 2],
	[-2, 0, 0, 2]
]

//双指针法

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		if (nums.size()<4) return{};
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		set<vector<int>> a;//去重
		for (int i = 0; i<nums.size() - 3; i++)
		{
			if (nums[i]>target&&target>0) break;
			for (int j = i + 1; j<nums.size() - 2; j++)
			{
				int l = j + 1;
				int r = nums.size() - 1;
				while (l<r)
				{
					if (nums[i] + nums[j] + nums[l] + nums[r]<target)
						l++;
					else if (nums[i] + nums[j] + nums[l] + nums[r]>target)
						r--;
					else
					{
						vector<int> temp{ nums[i], nums[j], nums[l], nums[r] };
						a.insert(temp);
						l++;
						r--;
					}
				}
			}
		}
		for (auto c : a)
		{
			res.push_back(c);
		}
		return res;
	}
};

