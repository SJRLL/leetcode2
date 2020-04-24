﻿给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。



示例 :
给定二叉树

    1
   / \
  2   3
 / \
4   5
返回 3, 它的长度是路径[4, 2, 1, 3] 或者 [5, 2, 1, 3]。

class Solution {
	int ans;
	int depth(TreeNode* rt){
		if (rt == NULL) return 0; // 访问到空节点了，返回0
		int L = depth(rt->left); // 左儿子为根的子树的深度
		int R = depth(rt->right); // 右儿子为根的子树的深度
		ans = max(ans, L + R + 1); // 计算d_node即L+R+1 并更新ans
		return max(L, R) + 1; // 返回该节点为根的子树的深度
	}
public:
	int diameterOfBinaryTree(TreeNode* root) {
		ans = 1;
		depth(root);
		return ans - 1;
	}
};
