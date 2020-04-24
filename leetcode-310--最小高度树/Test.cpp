对于一个具有树特征的无向图，我们可选择任何一个节点作为根。图因此可以成为树，在所有可能的树中，具有最小高度的树被称为最小高度树。给出这样的一个图，写出一个函数找到所有的最小高度树并返回他们的根节点。

格式

该图包含 n 个节点，标记为 0 到 n - 1。给定数字 n 和一个无向边 edges 列表（每一个边都是一对标签）。

你可以假设没有重复的边会出现在 edges 中。由于所有的边都是无向边，[0, 1]和 [1, 0] 是相同的，因此不会同时出现在 edges 里。

示例 1:

输入 : n = 4, edges = [[1, 0], [1, 2], [1, 3]]

	0
	|
	1
   / \
  2   3

输出:[1]


class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		vector<int> degree(n, 0);
		vector<vector<int>> points(n, vector<int>());

		if (edges.empty()) {
			return vector<int>(1, 0);
		}

		for (auto v : edges) {
			degree[v[0]]++;
			degree[v[1]]++;
			points[v[0]].push_back(v[1]);
			points[v[1]].push_back(v[0]);
		}
		int count = n;
		queue<int> leaf;
		for (int i = 0; i < degree.size(); i++) {
			if (degree[i] == 1) {
				leaf.push(i);
			}
		}

		while (!leaf.empty()) {
			if (n == 1 || n == 2) {
				break;
			}
			// if ((leaf.size() == 1 && degree[leaf.front()] == 0) || (leaf.size() == 2 && degree[leaf.front()] == 1)) {
			//     break;
			// }
			int k = leaf.size();
			while (k--) {
				n--;
				int d = leaf.front();
				leaf.pop();
				degree[d]--;
				int u = points[d][0];
				degree[u]--;
				points[u].erase(remove_if(points[u].begin(), points[u].end(), [d](int j) {
					if (j == d) {
						return true;
					}
					return false;
				}), points[u].end());
				if (degree[u] == 1) {
					leaf.push(u);
				}
			}
		}

		vector<int> res;
		while (!leaf.empty()) {
			res.push_back(leaf.front());
			leaf.pop();
		}

		return res;
	}
};
