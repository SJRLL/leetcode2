//题目描述：给你一个字符串 s ，请你返回满足以下条件且出现次数最大的 任意 子串的出现次数：

子串中不同字母的数目必须小于等于 maxLetters 。
子串的长度必须大于等于 minSize 且小于等于 maxSize 。


示例 1：

输入：s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
输出：2
解释：子串 "aab" 在原字符串中出现了 2 次。
它满足所有的要求：2 个不同的字母，长度为 3 （在 minSize 和 maxSize 范围内）。
示例 2：

输入：s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
输出：2
解释：子串 "aaa" 在原字符串中出现了 2 次，且它们有重叠部分。
示例 3：

输入：s = "aabcabcab", maxLetters = 2, minSize = 2, maxSize = 3
输出：3
示例 4：

输入：s = "abcde", maxLetters = 2, minSize = 3, maxSize = 3
输出：0

//解题思路： 要想 如果一个大于minsize的子串满足条件，那一个等于minsize的子串一定也满足。因此我们直接去检查minsize的子串就可以了。

class Solution {
public:
	map<string, int> mp;
	int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
		int len = s.size();
		for (int i = 0; i <= len - minSize; i++){
			int count[26] = { 0 };
			string subs = s.substr(i, minSize);
			for (auto c : subs) count[c - 'a']++;
			int keynums = 0;
			for (auto c : count) if (c>0) keynums++;
			if (keynums <= maxLetters){
				if (mp.find(subs) != mp.end()) mp[subs]++;
				else mp[subs] = 1;
			}
		}
		int res = 0;
		for (auto it : mp){
			res = res<(it.second) ? it.second : res;
		}
		return res;
	}
};
