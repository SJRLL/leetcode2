����һ�����������ҵ����·�������·���е�ÿ���ڵ������ֵͬ�� ����·�����Ծ���Ҳ���Բ��������ڵ㡣

ע�⣺�����ڵ�֮���·������������֮��ı�����ʾ��

ʾ�� 1:

���� :

	   5
	  / \
	 4   5
	/ \   \
   1   1   5
���:

   2
	   ʾ�� 2 :

���� :

	   1
	  / \
	 4   5
	/ \   \
   4   4   5
���:

2

//����˼·���ݹ������ô������ķ����������Լ�����û��͸����ô�����ģ����������ܹ���
//��ʵ���Դӵݹ����������ȵĽǶȳ�������ӽڵ���ӽڵ����ֵ�Ƚϣ��Լ�·�����ȵļ��㡣

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	int maxlen;
	int longestUnivaluePath(TreeNode* root) {
		maxlen = 0;
		samevallen(root);
		return maxlen;
	}

	int samevallen(TreeNode* node){
		if (node){
			int left_count = 0;
			if (node->left){
				if (node->val == node->left->val){
					left_count += 1;
					left_count += samevallen(node->left);
				}
				else {
					samevallen(node->left);
				}
			}
			int right_count = 0;
			if (node->right){
				if (node->val == node->right->val){
					right_count += 1;
					right_count += samevallen(node->right);
				}
				else {
					samevallen(node->right);
				}
			}
			maxlen = max(maxlen, left_count + right_count);
			return max(left_count, right_count);
		}
		return 0;
	}
};
