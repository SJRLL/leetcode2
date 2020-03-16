����һ���ɰ����ظ����ֵ����У��������в��ظ���ȫ���С�

ʾ�� :

���� : [1, 1, 2]
��� :
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
		//ö�ٵ�ʱ��ȥ�أ�ֻ��û���Ź���
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
