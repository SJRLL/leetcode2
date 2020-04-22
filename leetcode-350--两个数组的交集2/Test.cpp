给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入 : nums1 = [1, 2, 2, 1], nums2 = [2, 2]
输出 : [2, 2]
	 示例 2 :

输入 : nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]
输出 : [4, 9]


class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> v;
		unordered_map<int, int> unmap;
		for (auto e : nums1)
		{
			unmap[e]++;
		}

		for (auto e : nums2)
		{
			if (unmap.find(e) != unmap.end() && --unmap[e] >= 0)
			{
				v.push_back(e);
			}
		}
		return v;
	}
};