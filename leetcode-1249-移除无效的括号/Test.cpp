
给你一个由 '('、')' 和小写字母组成的字符串 s。

你需要从字符串中删除最少数目的 '(' 或者 ')' （可以删除任意位置的括号)，使得剩下的「括号字符串」有效。

请返回任意一个合法字符串。

有效「括号字符串」应当符合以下 任意一条 要求：

空字符串或只包含小写字母的字符串
可以被写作 AB（A 连接 B）的字符串，其中 A 和 B 都是有效「括号字符串」
可以被写作(A) 的字符串，其中 A 是一个有效的「括号字符串」


示例 1：

输入：s = "lee(t(c)o)de)"
输出："lee(t(c)o)de"
解释："lee(t(co)de)", "lee(t(c)ode)" 也是一个可行答案。
示例 2：

输入：s = "a)b(c)d"
输出："ab(c)d"
示例 3：

输入：s = "))(("
输出：""
解释：空字符串也是有效的
示例 4：

输入：s = "(a(b(c)d)"
输出："a(b(c)d)"

//解题思路：将所有的括号和它们的索引以pair<char,int>依次入栈，同时将配对的有效括号出栈，
//最后剩下的就是无效括号以及其索引，再利用剩下的索引在原字符串中删除对应的括号

class Solution {
public:
	string minRemoveToMakeValid(string s) {
		stack<pair<char, int>>ss;
		for (int i = 0; i<s.size(); i++){
			pair<char, int>t;
			t.first = s[i];
			t.second = i;
			if (!ss.empty()){
				if (ss.top().first == '('&&t.first == ')'){
					ss.pop();
					continue;
				}
				if (t.first == '('){
					ss.push(t);
					continue;
				}
			}
			if (t.first == '(' || t.first == ')'){
				ss.push(t);
			}
		}
		while (!ss.empty()){
			s.erase(s.begin() + ss.top().second);
			ss.pop();
		}
		return s;
	}
};
