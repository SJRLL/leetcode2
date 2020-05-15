﻿根据 百度百科 ，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。

给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态：1 即为活细胞（live），或 0 即为死细胞（dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：

如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
根据当前状态，写一个函数来计算面板上所有细胞的下一个（一次更新后的）状态。下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。



示例：

输入：
[
	[0, 1, 0],
	[0, 0, 1],
	[1, 1, 1],
	[0, 0, 0]
]
输出：
[
	[0, 0, 0],
	[1, 0, 1],
	[0, 1, 1],
	[0, 1, 0]
]

//解题思路
我们通过是否大于0来区别死亡和存活。
逐个遍历，假设遍历到board[i][j]，我们寻找board[i][j]8个位置存活数量，如果该位置的死亡或存活状态不变，则不做任何操作；如果由死亡变为存活，那么board[i][j]设为 - 1；存活变为死亡，则设为2；
处理完之后，在遍历一次，将2改为0， - 1改为1，时间复杂度是O(mn), 空间复杂度O(1)

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		int x, len1 = board.size();
		if (len1 == 0) return;
		int len2 = board[0].size();
		int tx[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };//八个位置
		int ty[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
		for (int i = 0; i<len1; i++)
		{
			for (int j = 0; j<len2; j++)
			{
				x = 0;
				for (int k = 0; k<8; k++)
				if (i + tx[k] >= 0 && i + tx[k]<len1 && j + ty[k] >= 0 && j + ty[k]<len2 && board[i + tx[k]][j + ty[k]]>0)//判断是否越界且大于0
					x++;
				if (board[i][j] == 0 && x == 3)
					board[i][j] = -1;//死亡变存活，但当前还是死亡(-1<=0)
				else if (board[i][j] == 1 && (x<2 || x>3))
					board[i][j] = 2;//存活变死亡，但当前还是存活(2>0)
			}
		}
		for (int i = 0; i<len1; i++)
		for (int j = 0; j<len2; j++)
		if (board[i][j] == -1) board[i][j] = 1;
		else if (board[i][j] == 2) board[i][j] = 0;
	}
};

