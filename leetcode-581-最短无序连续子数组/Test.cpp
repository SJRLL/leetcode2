给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。

你找到的子数组应是最短的，请输出它的长度。

示例 1:

输入 : [2, 6, 4, 8, 10, 9, 15]
输出 : 5
 解释 : 你只需要对[6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。

//解题思路：
单调栈
正向遍历，单调递增栈，找出自始至终没有出栈的最大索引 l
反向遍历，单调递减栈，找出自始至终没有出栈的最小索引 r
中间就是需要排序的最小子数组

int findUnsortedSubarray(vector<int>& nums)
{
	stack<int> st;
	int l = nums.size() - 1;
	int r = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		while (!st.empty() && nums[st.top()] > nums[i])
		{
			l = min(l, st.top());
			st.pop();
		}
		st.push(i);
	}
	st = stack<int>();
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		while (!st.empty() && nums[st.top()] < nums[i])
		{
			r = max(r, st.top());
			st.pop();
		}
		st.push(i);
	}
	return (r > l) ? r - l + 1 : 0;
}
