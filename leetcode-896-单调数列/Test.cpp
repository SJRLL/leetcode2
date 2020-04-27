如果数组是单调递增或单调递减的，那么它是单调的。

如果对于所有 i <= j，A[i] <= A[j]，那么数组 A 是单调递增的。 如果对于所有 i <= j，A[i]> = A[j]，那么数组 A 是单调递减的。

当给定的数组 A 是单调数组时返回 true，否则返回 false。



示例 1：

输入：[1, 2, 2, 3]
输出：true
示例 2：

输入：[6, 5, 4, 4]
输出：true
示例 3：

输入：[1, 3, 2]
输出：false
示例 4：

输入：[1, 2, 4, 5]
输出：true
示例 5：

输入：[1, 1, 1]
输出：true

解题思路：确保一次一次循环，且为升序
class Solution {
public:
	bool isMonotonic(vector<int>& A) {
		// 不要求严格单调递增,判别是递增还是递减
		bool tag = false;
		if (A.size() < 3) return true;
		int num = A[0];
		int i = 1;
		while (i<A.size() && A[i] == A[0])
			++i;
		if (i == A.size()) 
			return true;
		if (A[0] > A[i]) 
			tag = true; //单调递减
		if (tag)
		{
			for (; i<A.size(); ++i)
			{
				if (A[i] > A[i - 1])
					return false;
			}
			return true;
		}
		else
		{
			for (; i<A.size(); ++i)
			{
				if (A[i] < A[i - 1]) 
					return false;
			}
			return true;
		}
	}
};
