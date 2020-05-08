给定一个正整数 n，返回长度为 n 的所有可被视为可奖励的出勤记录的数量。 答案可能非常大，你只需返回结果mod 109 + 7的值。

学生出勤记录是只包含以下三个字符的字符串：

'A' : Absent，缺勤
'L' : Late，迟到
'P' : Present，到场
如果记录不包含多于一个'A'（缺勤）或超过两个连续的'L'（迟到），则该记录被视为可奖励的。

示例 1 :

输入 : n = 2
 输出 : 8
	  解释：
	  有8个长度为2的记录将被视为可奖励：
	  "PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"
	  只有"AA"不会被视为可奖励，因为缺勤次数超过一次。

//记忆搜索，不断更新记录
class Solution {
public:
	int mod = 1e9 + 7;
	int dp[100001][2][3];
	int checkRecord(int n) {
		memset(dp, -1, sizeof(int)* 100001 * 2 * 3);
		return dfs(0, 0, 0, n);
	}
	int dfs(int i, int a, int l, int n){
		if (dp[i][a][l] != -1) return dp[i][a][l];
		if (i == n) return 1;
		int ans = 0;
		if (a == 0) ans = (ans + dfs(i + 1, 1, 0, n)) % mod;
		if (l == 2) ans = (ans + dfs(i + 1, a, 0, n)) % mod;
		else{
			ans = (ans + dfs(i + 1, a, l + 1, n)) % mod;
			ans = (ans + dfs(i + 1, a, 0, n)) % mod;
		}
		dp[i][a][l] = ans;
		return ans;
	}
};
