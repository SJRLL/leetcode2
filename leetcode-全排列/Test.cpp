����һ��û���ظ����ֵ����У����������п��ܵ�ȫ���С�

ʾ�� :

���� : [1, 2, 3]
��� :
   [
	   [1, 2, 3],
	   [1, 3, 2],
	   [2, 1, 3],
	   [2, 3, 1],
	   [3, 1, 2],
	   [3, 2, 1]
   ]

//����˼·��
	 ���ڵ�ǰ��nums[k], ��ǰ���������˳��̶���
	������������źã�perm(k + 1)��, ֻ��Ҫ��������������������Ϳ��Եõ�perm��k������k��k���������ȫ���У�
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