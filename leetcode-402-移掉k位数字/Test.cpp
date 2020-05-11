给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。

注意 :

num 的长度小于 10002 且 ≥ k。
num 不会包含任何前导零。
示例 1 :

输入 : num = "1432219", k = 3
 输出 : "1219"
  解释 : 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。
	   示例 2 :

输入 : num = "10200", k = 1
输出 : "200"
解释 : 移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
		  示例 3 :

输入 : num = "10", k = 2
 输出 : "0"
解释 : 从原数字移除所有的数字，剩余为空就是0。

//解题思路
//1，单调栈记录遍历过的左侧下边界
//2，随着从左到后遍历字符逐渐更新单调栈

class Solution {
public:
	string removeKdigits(string num, int k) {
		stack<char> st;
		for (auto c : num) 
		{
			while (!st.empty() && st.top() > c && k > 0)
			{
				st.pop();
				--k;
			}
			if (st.empty() && c == '0') 
				continue;
			st.push(c);
		}
		while (!st.empty() && k > 0) 
		{
			st.pop();
			--k;
		}
		string res;
		while (!st.empty()) 
		{
			res += st.top();
			st.pop();
		}
		reverse(res.begin(), res.end());
		return res.empty() ? "0" : res;
	}
};

