数组的每个索引做为一个阶梯，第 i个阶梯对应着一个非负数的体力花费值 cost[i](索引从0开始)。

每当你爬上一个阶梯你都要花费对应的体力花费值，然后你可以选择继续爬一个阶梯或者爬两个阶梯。

您需要找到达到楼层顶部的最低花费。在开始时，你可以选择从索引为 0 或 1 的元素作为初始阶梯。

示例 1 :

输入 : cost = [10, 15, 20]
输出 : 15
 解释 : 最低花费是从cost[1]开始，然后走两步即可到阶梯顶，一共花费15。
	  示例 2 :

输入 : cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
输出 : 6
解释 : 最低花费方式是从cost[0]开始，逐个经过那些1，跳过cost[3]，一共花费6。

动态规划的思想:
1.设置数组Dp[], Dp[i]表示到达第i阶楼梯所需花费的最小体力
2.边界值 : 初始楼梯为第一个或第二个 : Dp[0] = cost[0], Dp[1] = cost[1]
3.状态转移方程 : Dp[k] = min(Dp[k - 1] + cost[k], Dp[k - 2] + cost[k])
4.因为最后可以不经过最后一个楼梯, 可以从倒数第二个直接上两个楼梯直接上去，所以需要比较Dp[length - 1]和Dp[length - 2]的大小
其中length为楼梯的长度

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int length = cost.size();
		int dp[length + 5] = { 0 };
		dp[0] = cost[0];
		dp[1] = cost[1];
		for (int k = 2; k<cost.size(); k++){
			dp[k] = min(dp[k - 1] + cost[k], dp[k - 2] + cost[k]);
		}
		return dp[length - 1]>dp[length - 2] ? dp[length - 2] : dp[length - 1];
	}
};
