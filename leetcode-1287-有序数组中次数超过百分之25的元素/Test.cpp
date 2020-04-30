给你一个非递减的 有序 整数数组，已知这个数组中恰好有一个整数，它的出现次数超过数组元素总数的 25 % 。

请你找到并返回这个整数



示例：

输入：arr = [1, 2, 2, 6, 6, 6, 6, 7, 10]
输出：6

//解题思路：由于数组 arr 已经有序，那么相同的数在 arr 中出现的位置也是连续的。因此我们可以对数组进行一次遍历，
//并统计每个数出现的次数。只要发现某个数出现的次数超过数组 arr 长度的 25%，那么这个数即为答案。

//在计算数组 arr 长度的 25 % 时，会涉及到浮点数。我们可以用整数运算 count * 4 > arr.length 代替浮点数运算 count > arr.length * 25 % ，
//减少精度误差。

class Solution {
public:
	int findSpecialInteger(vector<int>& arr) {
		int n = arr.size();
		int cur = arr[0], cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (arr[i] == cur) {
				++cnt;
				if (cnt * 4 > n) {
					return cur;
				}
			}
			else {
				cur = arr[i];
				cnt = 1;
			}
		}
		return -1;
	}
};
