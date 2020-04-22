删除最小数量的无效括号，使得输入的字符串有效，返回所有可能的结果。

说明 : 输入可能包含了除 (和 ) 以外的字符。

	 示例 1 :

输入 : "()())()"
输出 : ["()()()", "(())()"]
	   示例 2 :

输入 : "(a)())()"
输出 : ["(a)()()", "(a())()"]
		 示例 3 :

输入 : ")("
输出 : [""]

class Solution {
public:
	vector<string> res;
	vector<string> removeInvalidParentheses(string s) {
		int left = 0, right = 0;
		for (auto c : s){
			if (c == '('){
				left++;
			}
			else if (c == ')'){
				if (left > 0) {
					left--;
				}
				else {
					right++;
				}
			}
		}

		int start = 0;
		dfs(s, start, left, right);
		return res;
	}
	void dfs(string s, int start, int l, int r){
		if (l == 0 && r == 0) {
			if (is_valid(s)) {
				res.push_back(s);
			}
			return;
		}
		for (int i = start; i<s.size(); i++){
			if (i != start && s[i] == s[i - 1]) continue;
			if (s[i] == '(' && l > 0) {
				dfs(s.substr(0, i) + s.substr(i + 1, s.size() - 1 - i), i, l - 1, r);
			}
			if (s[i] == ')' && r > 0) {
				dfs(s.substr(0, i) + s.substr(i + 1, s.size() - 1 - i), i, l, r - 1);
			}
		}
	}
	bool is_valid(string s) {
		int cnt = 0;
		for (auto c : s) {
			if (c == '(') {
				cnt++;
			}
			else if (c == ')') {
				cnt--;
				if (cnt < 0) return false;
			}
		}
		return cnt == 0;
	}

};
