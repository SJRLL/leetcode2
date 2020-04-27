对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1, 2, 3, 1]。

给定非负整数 X 的数组形式 A，返回整数 X + K 的数组形式。



示例 1：

输入：A = [1, 2, 0, 0], K = 34
输出：[1, 2, 3, 4]
解释：1200 + 34 = 1234
示例 2：

输入：A = [2, 7, 4], K = 181
输出：[4, 5, 5]
解释：274 + 181 = 455
示例 3：

输入：A = [2, 1, 5], K = 806
输出：[1, 0, 2, 1]
解释：215 + 806 = 1021
示例 4：

输入：A = [9, 9, 9, 9, 9, 9, 9, 9, 9, 9], K = 1
输出：[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
解释：9999999999 + 1 = 10000000000


解题思路：思路和67题二进制求和一样，不要转成数字去做，内存吃不起，就用各个位累加前推方法
先补位，再依次相加，处理好进位关系即可。

class Solution {
public:
	vector<int> addToArrayForm(vector<int>& A, int K) {
		vector<int> kk;
		while (K){
			kk.insert(kk.begin(), K % 10);
			K /= 10;
		}

		int a = A.size(); int b = kk.size();
		while (a<b){
			A.insert(A.begin(), 0);
			a++;
		}
		while (a>b){
			kk.insert(kk.begin(), 0);
			b++;
		}

		int carry = 0;
		for (int i = a - 1; i >= 0; i--){
			int sum = A[i] + kk[i] + carry;
			A[i] = sum % 10;
			carry = sum / 10;
		}
		if (carry>0) A.insert(A.begin(), carry);
		return A;
	}
};
