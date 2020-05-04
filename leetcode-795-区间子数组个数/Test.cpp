给定一个元素都是正整数的数组A ，正整数 L 以及 R(L <= R)。

求连续、非空且其中最大元素满足大于等于L 小于等于R的子数组个数。

例如 :
输入 :
	A = [2, 1, 4, 3]
	L = 2
	R = 3
输出 : 3
 解释 : 满足条件的子数组 : [2], [2, 1], [3].

//解题思路：维护两个数据：目前为止最后一个大于R的数对应的索引(lastLargeThanRNumIndex)和最后一个位于区间[L,R]的数据的索引(lastInTheRangeNumIndex)；

//当A[i] > R时，更新lastLargeThanRNumIndex

//当A[i] < L时，如果lastInTheRangeNumIndex != -1 并且 lastInTheRangeNumIndex > lastLargeThanRNumIndex ，则有可能构成满足要求的区间, 形式为：

A[(lastLargeThanRNumIndex + 1)...lastInTheRangeNumIndex...i]。

//A[i]位于[L, R]中间时，更新lastInTheRangeNumIndex，则可能构成满足要求的区间，形式为A[(lastLargeThanRNumIndex + 1)...i]。

class Solution {
public:
	int numSubarrayBoundedMax(vector<int> &A, int L, int R) {
		int ans = 0;
		int lastLargeThanRNumIndex = -1;
		int lastInTheRangeNumIndex = -1;
		for (int i = 0; i < A.size(); ++i) 
		{
			if (A[i] > R) 
			{
				lastLargeThanRNumIndex = i;
			}
			else if (A[i] < L) 
			{
				if (lastInTheRangeNumIndex != -1 && lastInTheRangeNumIndex > lastLargeThanRNumIndex) 
				{
					ans += lastInTheRangeNumIndex - lastLargeThanRNumIndex;
				}
			}
			else 
			{
				lastInTheRangeNumIndex = i;
				ans += i - lastLargeThanRNumIndex;
			}
		}
		return ans;
	}
};

