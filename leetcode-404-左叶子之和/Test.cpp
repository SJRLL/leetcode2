计算给定二叉树的所有左叶子之和。

示例：

   3
  / \
 9  20
   / \
 15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

//解题思路：递归
class Solution {
public:
	int ans = 0;
	int sumOfLeftLeaves(TreeNode* root) 
	{
		leftNum(root);
		return ans;
	}

	void leftNum(TreeNode *root)
	{
		//到达叶子返回
		if (root == NULL) return;
		//判断某一个节点的左子数是否叶子节点，是就将左子树的值增加到ans中（叶子节点没有左右子树）
		if (root->left != NULL && (root->left->left == NULL && root->left->right == NULL))
		{
			ans += root->left->val;
		}
		leftNum(root->left);
		leftNum(root->right);
	}

};

