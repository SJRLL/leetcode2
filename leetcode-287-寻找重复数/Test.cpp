﻿给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。

示例 1:

输入 : [1, 3, 4, 2, 2]
输出 : 2
	 示例 2 :

 输入 : [3, 1, 3, 4, 2]
  输出 : 3
	   说明：

	   不能更改原数组（假设数组是只读的）。
	   只能使用额外的 O(1) 的空间。
	   时间复杂度小于 O(n2) 。
	   数组中只有一个重复的数字，但它可能不止重复出现一次。

//解题思路：二分法 - 时间复杂度 O(n * log n) - 空间复杂度 O(1)

class Solution {
	 public:
		 int findDuplicate(vector<int>& nums) {
			 int left = 0, mid, right = nums.size() - 1;

			 while (left < right) 
			 {
				 int cnt = 0;
				 mid = left + (right - left) / 2;

				 for (int i = 0; i < nums.size(); i++) 
				 {
					 if (nums[i] <= mid)   cnt += 1;
				 }

				 // 根据抽屉原理，小于等于 x 的数字个数如果严格大于 x，则说明重复元素在区间 [1, x] 中
				 if (cnt > mid)
					 // 重复元素在区间 [1, mid] 中
					 right = mid;
				 else
					 // 重复元素在上面区间的反面 [mid + 1, right] 中
					 left = mid + 1;
			 }

			 return left;
		 }
};
