����һ�� N ������������ڵ�ֵ�ĺ��������

���磬����һ�� 3���� :

//����˼·��˳��ݹ鴦��ǰ�ڵ��children���ٽ���ǰ�ڵ��ֵ��������(�ڴ����Ľϴ�)
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

//����˼·��ǰ��ӷ�ת��ע���ǰ��Ľ�ջ˳��
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
