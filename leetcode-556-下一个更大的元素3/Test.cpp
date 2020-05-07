
给定一个32位正整数 n，你需要找到最小的32位整数，其与 n 中存在的位数完全相同，并且其值大于n。如果不存在这样的32位整数，则返回 - 1。

示例 1:

输入 : 12
输出 : 21
	 示例 2 :

 输入 : 21
  输出 : -1

//解题思路:对于大于INT_MAX的数需要返回 - 1！！！

class Solution {
public:
	int nextGreaterElement(int n) {
		string temp = to_string(n); int flag = -1;
		for (int i = temp.size() - 1; i>0; --i)
		{
			if (temp[i]>temp[i - 1])
			{
				flag = i - 1;
				break;
			}
		}
		if (flag == -1)
			return -1;
		char max1 = '9';
		int maxin;
		for (int i = flag + 1; i<temp.size(); ++i)
		{
			if (temp[i]>temp[flag] && temp[i] <= max1)
			{
				max1 = temp[i];
				maxin = i;
			}
		}
		swap(temp[maxin], temp[flag]);
		sort(temp.begin() + flag + 1, temp.end());
		if (stoll(temp)>INT_MAX) return -1;
		return stoll(temp);
	}
};
