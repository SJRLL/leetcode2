给定一个 N 叉树，返回其节点值的后序遍历。

例如，给定一个 3叉树 :

//解题思路：顺序递归处理当前节点的children，再将当前节点的值存入数组(内存消耗较大)
class Solution {
public:
	vector <int> a;
	vector<int> postorder(Node* root) {
		if (!root) return a;
		f(root);
		return a;
	}

	void f(Node* root){
		Node* tmp;
		for (int i = 0; i < root->children.size(); i++){
			tmp = root->children[i];
			f(tmp);
		}
		a.push_back(root->val);
	}
};

//解题思路：前序加翻转，注意和前序的进栈顺序
class Solution {
public:
	vector<int> postorder(Node* root) {
		vector<int> res;
		if (!root) return res;

		stack<Node*> s;
		s.push(root);

		while (!s.empty()){
			Node* cur = s.top();
			s.pop();
			res.push_back(cur->val);

			for (auto node : cur->children){
				s.push(node);
			}
		}

		reverse(res.begin(), res.end());
		return res;
	}
};
