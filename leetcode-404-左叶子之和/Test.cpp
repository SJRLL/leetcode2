���������������������Ҷ��֮�͡�

ʾ����

   3
  / \
 9  20
   / \
 15   7

������������У���������Ҷ�ӣ��ֱ��� 9 �� 15�����Է��� 24

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

//����˼·���ݹ�
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
		//����Ҷ�ӷ���
		if (root == NULL) return;
		//�ж�ĳһ���ڵ���������Ƿ�Ҷ�ӽڵ㣬�Ǿͽ���������ֵ���ӵ�ans�У�Ҷ�ӽڵ�û������������
		if (root->left != NULL && (root->left->left == NULL && root->left->right == NULL))
		{
			ans += root->left->val;
		}
		leftNum(root->left);
		leftNum(root->right);
	}

};

