给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。

说明：

分隔时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入 :
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
输出 :
   [
	   "cats and dog",
	   "cat sand dog"
   ]
示例 2：

输入 :
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
输出 :
   [
	   "pine apple pen apple",
	   "pineapple pen apple",
	   "pine applepen apple"
   ]
解释 : 注意你可以重复使用字典中的单词。
	示例 3：

输入 :
	 s = "catsandog"
		 wordDict = ["cats", "dog", "sand", "and", "cat"]
	 输出 :
		[]

//解题思路：因此需要对上面算法进行优化，避免重复计算，参考各位大佬们的答案之后，将每个字符串对应的结果保存在map结构中，这样可以减少重复运算
	// ，最终实现如下，可以成功通过。
	 //回溯 + 剪枝，利用一个map保留键值映射，想相当于加入剪枝操作，可以对之前计算过的避免重复计算，进而加速计算过程，
	 //注意helper中的m.count(s)的判断非常必要，如果已经存在就直接调用之前计算的结果，加速计算。

class Solution {
public:
	vector<string> wordBreak(string s, vector<string>& wordDict)
	{
		unordered_map<string, vector<string> > m;
		return helper(m, wordDict, s);
	}
	vector<string> helper(unordered_map<string, vector<string> >& m, vector<string>& wordDict, string s)
	{
		if (m.count(s)) 
			return m[s];
		if (s.empty()) 
			return{ "" };
		vector<string> res;
		for (auto word : wordDict)
		{
			if (s.substr(0, word.size()) != word)
				continue;
			vector<string> tmp = helper(m, wordDict, s.substr(word.size()));
			for (auto itm : tmp)
			{
				res.push_back(word + (itm.empty() ? "" : " " + itm));
			}
		}
		m[s] = res;
		return res;
	}
};
