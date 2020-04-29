回旋镖定义为一组三个点，这些点各不相同且不在一条直线上。

给出平面上三个点组成的列表，判断这些点是否可以构成回旋镖。



示例 1：

输入：[[1, 1], [2, 3], [3, 2]]
输出：true
示例 2：

输入：[[1, 1], [2, 2], [3, 3]]
输出：false

首先分母不能为0，其次各个坐标不相等，再斜率不等（注意整除时用double），则true。

class Solution {
public:
	bool isBoomerang(vector<vector<int>>& points) {
		bool f = 0;
		double k1 = 0, k2 = 0;
		if (points[0][1] - points[1][1] == 0)
		{
			k1 = INT_MAX;
		}

		if (points[1][1] - points[2][1] == 0)
		{
			k2 = INT_MAX;
		}
		if (points[0] != points[1] && points[0] != points[2] && points[2] != points[1])
		{
			if (k1 != INT_MAX) k1 = (double)
				(points[0][0] - points[1][0]) / (points[0][1] - points[1][1]);
			if (k2 != INT_MAX) k2 = (double)
				(points[1][0] - points[2][0]) / (points[1][1] - points[2][1]);
			if (k1 != k2) f = 1;
		}
		return f;
	}
};
