给定平面上 n 对不同的点，“回旋镖” 是由点表示的元组 (i, j, k) ，其中 i 和 j 之间的距离和 i 和 k 之间的距离相等（需要考虑元组的顺序）。

找到所有回旋镖的数量。你可以假设 n 最大为 500，所有点的坐标在闭区间[-10000, 10000] 中。

示例 :

输入 :
	[[0, 0], [1, 0], [2, 0]]

输出 :
	2

解释 :
   两个回旋镖为[[1, 0], [0, 0], [2, 0]] 和[[1, 0], [2, 0], [0, 0]]

//解题思路：思路很直观，每次选中一组作为轴，也就是代码里面的pivot，遍历其他元素，根据距离分组。
   //因为我们选中了一个pivot，所以再补上两个就是一个完整的镖了，按照排列的思想就是n个里面排2个，也就是n*(n - 1)这样加起来就是答案啦。

	   class Solution {
	   public:
		   int numberOfBoomerangs(vector<vector<int>>& points) {
			   unordered_map<int, int> distCount;

			   int boomerangsCount(0);
			   for (int i = 0; i < points.size(); ++i) {
				   distCount.clear();
				   vector<int> pivot(points[i]);

				   for (int j = 0; j < points.size(); ++j)
					   ++distCount[pow(points[j][0] - pivot[0], 2) + pow(points[j][1] - pivot[1], 2)];

				   for (auto distNum : distCount) boomerangsCount += distNum.second * (distNum.second - 1);
			   }

			   return boomerangsCount;
		   }
	   };
