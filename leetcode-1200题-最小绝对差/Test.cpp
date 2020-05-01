//题目描述：给你个整数数组 arr，其中每个元素都 不相同。请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。

示例 1：

输入：arr = [4, 2, 1, 3]
输出：[[1, 2], [2, 3], [3, 4]]
示例 2：

输入：arr = [1, 3, 6, 10, 15]
输出：[[1, 3]]
示例 3：

输入：arr = [3, 8, -10, 23, 19, -4, -14, 27]
输出：[[-14, -10], [19, 23], [23, 27]]

//解题思路：一开始用map，并不需要，只能是相邻的两个，直接比较就可以了

	class Solution {
	public:
		vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
			sort(arr.begin(), arr.end());
			vector<vector<int>> res;
			map<int, int> m;
			int min = INT_MAX;
			for (int i = 0; i<arr.size() - 1; i++){ //找出最小的差
				int now = arr[i + 1] - arr[i];
				if (now<min) min = now;
			}
			for (int i = 0; i<arr.size() - 1; i++){ //遍历数组，如果这个数+最小差存在就把它们返回
				vector<int> temp(2);
				if (arr[i + 1] - arr[i] == min) {
					temp[0] = arr[i];
					temp[1] = arr[i + 1];
					res.push_back(temp);
				}
			}
			return res;
		}
	};
