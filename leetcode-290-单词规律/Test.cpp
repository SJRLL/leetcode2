给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

示例1 :

输入 : pattern = "abba", str = "dog cat cat dog"
输出 : true
	 示例 2 :

输入 : pattern = "abba", str = "dog cat cat fish"
输出 : false
	   示例 3 :

输入 : pattern = "aaaa", str = "dog cat cat dog"
输出 : false

	 示例 4 :

输入 : pattern = "abba", str = "dog dog dog dog"
输出 : false


class Solution {
public:
	bool wordPattern(string pattern, string str) {
		map<string, char> m;
		int use[128] = { 0 };
		string word = "";
		int i = 0, pos = 0;
		str += ' ';
		for (i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ')
			{
				if (pos == pattern.length())
				{
					return false;
				}
				if (m.find(word) == m.end())
				{
					if (use[pattern[pos]])
					{
						return false;
					}
					m[word] = pattern[pos];
					use[pattern[pos]] = 1;
				}
				else
				{
					if (m[word] != pattern[pos])
					{
						return false;
					}
				}
				word = "";
				pos++;
			}
			else
			{
				word += str[i];
			}
		}
		if (pos != pattern.length())
		{
			return false;
		}
		return true;
	}
};

