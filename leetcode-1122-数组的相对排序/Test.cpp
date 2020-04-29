给你两个数组，arr1 和 arr2，

arr2 中的元素各不相同
arr2 中的每个元素都出现在 arr1 中
对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。



示例：

输入：arr1 = [2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19], arr2 = [2, 1, 4, 3, 9, 6]
输出：[2, 2, 2, 1, 4, 3, 3, 9, 6, 7, 19]

//解题思路：第一种计数排序，先统计每个arr1中每个数字i出现的次数n_i，然后遍历arr2中的每个索引j，根据统计结果将j输出n_j次。
//最后把剩下的元素按从小到大顺序输出出来（就是把统计数组中的每一个元素输出）。

	class Solution {
	public:
		vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
			vector<int> result;
			int counter[1001] = { 0 };
			for (auto it = arr1.begin(); it != arr1.end(); ++it){
				counter[*it] ++;
			}
			for (auto it = arr2.begin(); it != arr2.end(); ++it){
				for (auto i = 0; i < counter[*it]; ++i){
					result.push_back(*it);
				}
				counter[*it] = 0;
			}
			for (auto i = 0; i < 1001; ++i){
				if (counter[i] != 0){
					for (auto j = 0; j < counter[i]; ++j){
						result.push_back(i);
					}
				}
			}
			return result;
		}
	};
