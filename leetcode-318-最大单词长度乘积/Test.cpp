﻿给定一个字符串数组 words，找到 length(word[i]) * length(word[j]) 的最大值，并且这两个单词不含有公共字母。你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。

示例 1 :

输入 : ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
输出 : 16
 解释 : 这两个单词为 "abcw", "xtfn"。
	  示例 2 :

输入 : ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
输出 : 4
 解释 : 这两个单词为 "ab", "cd"。

		 示例 3 :

输入 : ["a", "aa", "aaa", "aaaa"]
输出 : 0
解释 : 不存在这样的两个单词。


class Solution {
public:
	int maxProduct(vector<string>& words) {
		vector<int> len;
		vector<int> charbit;
		int x;
		for (string word : words)
		{
			x = 0;
			for (char c : word)
			{
				int tmp = pow(2, c - 'a');
				x = x | tmp;
			}
			charbit.push_back(x);
			len.push_back(word.size());
		}
		int ret = 0;
		for (int i = 0; i<len.size(); ++i)
		for (int j = i + 1; j<len.size(); ++j)
		if ((charbit[i] & charbit[j]) == 0)
			ret = max(ret, len[i] * len[j]);

		return ret;

	}
};
