����һ�� N ������������ڵ�ֵ��ǰ�������

���磬����һ�� 3���� :

//����˼·���ǵݹ飬����뱣֤��������������ȱ���������ô����Ҫ����ջ�ˣ���ջʱ����Ҫ���ӽ�����������ջ����֤����ӽ���ȱ�����

class Solution {
public:
	vector<int> preorder(Node* root) {
		vector<int> ans;
		stack<Node*> s;
		if (root)
			s.push(root);
		while (!s.empty()) {
			Node* p = s.top();
			ans.push_back(p->val);
			s.pop();
			int len = p->children.size();
			for (int i = len - 1; i >= 0; i--) {
				if (p->children[i])
					s.push(p->children[i]);
			}
		}
		return ans;
	}
};

