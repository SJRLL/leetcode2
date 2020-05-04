用字符串数组作为井字游戏的游戏板 board。当且仅当在井字游戏过程中，玩家有可能将字符放置成游戏板所显示的状态时，才返回 true。

该游戏板是一个 3 x 3 数组，由字符 " "，"X" 和 "O" 组成。字符 " " 代表一个空位。

以下是井字游戏的规则：

玩家轮流将字符放入空位（" "）中。
第一个玩家总是放字符 “X”，且第二个玩家总是放字符 “O”。
“X” 和 “O” 只允许放置在空位中，不允许对已放有字符的位置进行填充。
当有 3 个相同（且非空）的字符填充任何行、列或对角线时，游戏结束。
当所有位置非空时，也算为游戏结束。
如果游戏结束，玩家不允许再放置字符。
示例 1:
输入 : board = ["O  ", "   ", "   "]
输出 : false
 解释 : 第一个玩家总是放置“X”。

示例 2 :
  输入 : board = ["XOX", " X ", "   "]
   输出 : false
	解释 : 玩家应该是轮流放置的。

示例 3 :
	 输入 : board = ["XXX", "   ", "OOO"]
	  输出 : false

示例 4 :
	   输入 : board = ["XOX", "O O", "XOX"]
		输出 : true

//解题思路：分类讨论即，题目跟递归没关系，硬要用递归可能就是列出所有有效的组合。

class Solution {
public:
inline bool checkWin(vector<string> & board, const char & c) {
	/* 判断行和列 */
	for (int i = 0; i < 3; ++i) {
		if (c == board[i][0] && c == board[i][1] && c == board[i][2]) 
		{
			return true;
		}
		if (c == board[0][i] && c == board[1][i] && c == board[2][i]) 
		{
			return true;
		}
	}
	/* 判断对角线 */
	if (c == board[0][0] && c == board[1][1] && c == board[2][2]) {

		return true;
	}
	if (c == board[2][0] && c == board[1][1] && c == board[0][2]) 
	{
		return true;
	}
	return false;
}
bool validTicTacToe(vector<string> & board) 
{
	int count = 0;
	for (int i = 0; i < 3; ++i) 
	{

		for (int j = 0; j < 3; ++j)
		{
			if ('X' == board[i][j]) 
			{
				++count;
			}
			else if ('O' == board[i][j])
			{
				--count;
			}
		}
	}
	if (count < 0 || count > 1)
	{
		return false;
	}
	bool XWin = checkWin(board, 'X');
	bool OWin = checkWin(board, 'O');
	if (XWin && !OWin) {
		return 1 == count;
	}
	else if (!XWin && OWin) 
	{
		return 0 == count;
	}
	else if (XWin && OWin) 
	{
		return false;
	}
	return true;
}
};

