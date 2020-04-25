在英语中，我们有一个叫做 词根(root)的概念，它可以跟着其他一些词组成另一个较长的单词——我们称这个词为 继承词(successor)。例如，词根an，跟随着单词 other(其他)，可以形成新的单词 another(另一个)。

现在，给定一个由许多词根组成的词典和一个句子。你需要将句子中的所有继承词用词根替换掉。如果继承词有许多可以形成它的词根，则用最短的词根替换它。

你需要输出替换之后的句子。



示例：

输入：dict(词典) = ["cat", "bat", "rat"] sentence(句子) = "the cattle was rattled by the battery"
输出："the cat was rat by the bat"


//解题思路：先构建一个词典set，然后对sentence中的每个单词init，判断是否存在词根在set中

class Solution {
public:
	string replaceWords(vector<string>& dict, string sentence) {
		set<string> s;
		for (auto& a : dict)
			s.insert(a);
		stringstream ss(sentence);
		string ret;
		string init;
		if (sentence.empty())
			return ret;
		while (ss >> init)
		{
			for (int i = 0; i<init.size(); i++)
			{
				if (s.find(init.substr(0, i)) != s.end())
				{
					init = init.substr(0, i);
				}
			}
			ret = ret + init + ' ';
		}
		ret.erase(ret.end() - 1);
		return ret;
	}
};
