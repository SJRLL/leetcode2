﻿给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，并采用两种不同的形式之一："a==b" 或 "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。

只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。 



示例 1：

输入：["a==b", "b!=a"]
输出：false
解释：如果我们指定，a = 1 且 b = 1，那么可以满足第一个方程，但无法满足第二个方程。没有办法分配变量同时满足这两个方程。
示例 2：

输出：["b==a", "a==b"]
输入：true
解释：我们可以指定 a = 1 且 b = 1 以满足满足这两个方程。
示例 3：

输入：["a==b", "b==c", "a==c"]
输出：true
示例 4：

输入：["a==b", "b!=c", "c==a"]
输出：false
示例 5：

输入：["c==c", "b==d", "x!=z"]
输出：true

//解题思路：先处理 == 的情况，若a == b，则令dp['a' - 'a']['b' - 'a'] = 1，再处理 != 的情况，对于x != y，通过dfs判断x与y是否连通，flag[]为辅助数组标记节点是否遍历过以方便回溯

class Solution {
public:
	int dp[26][26];
	int flag[26];
	bool dfs(int x, int y){
		if (dp[x][y] == 1)
			return true;
		else{
			bool res = false;
			flag[x] = 1;
			for (int i = 0; i<26; i++)
			if (dp[x][i] == 1 && flag[i] == 0){
				flag[i] = 1;
				res = res || dfs(i, y);
				if (res == true)
					return true;
				flag[i] = 0;
			}
			flag[x] = 0;
			return res;
		}
	}
	bool equationsPossible(vector<string>& equations) {
		for (int i = 0; i<26; i++)
		for (int j = 0; j<26; j++)
		if (i == j)
			dp[i][j] = 1;
		else
			dp[i][j] = 0;
		for (int i = 0; i<26; i++)
			flag[i] = 0;
		for (int i = 0; i<equations.size(); i++)
		if (equations[i][1] == '='){
			dp[equations[i][0] - 'a'][equations[i][3] - 'a'] = 1;
			dp[equations[i][3] - 'a'][equations[i][0] - 'a'] = 1;
		}
		for (int i = 0; i<equations.size(); i++)
		if (equations[i][1] == '!')
		if (dfs(equations[i][0] - 'a', equations[i][3] - 'a'))
			return false;
		return true;
	}
};
