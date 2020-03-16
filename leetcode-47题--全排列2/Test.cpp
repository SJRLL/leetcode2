给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例 :

输入 : [1, 1, 2]
输出 :
   [
	   [1, 1, 2],
	   [1, 2, 1],
	   [2, 1, 1]
   ]

class Solution {
public:

	vector<vector<int>> permuteUnique(vector<int>& a)
	{
		vector<vector<int>> res;
		bt(a, res, 0);
		return res;
	}
	void bt(vector<int>& a, vector<vector<int>>& res, int level)
	{
		if (level == a.size())
		{
			res.push_back(a);
			return;
		}
		//枚举的时候去重，只用没有排过的
		unordered_set<int> uniq;
		for (int i = level; i < a.size(); ++i)
		{
			if (uniq.count(a[i]))
			{
				continue; //already used
			}
			swap(a[i], a[level]);
			bt(a, res, level + 1);
			swap(a[i], a[level]);
			uniq.insert(a[i]);
		}
	}
};
