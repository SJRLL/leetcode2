给定两个字符串 A 和 B, 寻找重复叠加字符串A的最小次数，使得字符串B成为叠加后的字符串A的子串，如果不存在则返回 - 1。

举个例子，A = "abcd"，B = "cdabcdab"。

答案为 3， 因为 A 重复叠加三遍后为 “abcdabcdabcd”，此时 B 是其子串；A 重复叠加两遍后为"abcdabcd"，B 并不是其子串。

//解题思路：重复累加，当B.size()+temp.size()<n*A.size()时仍不是子串时，就可以判断false了！
//原理是因为继续累加temp得到的知识重复的结果，没有意义。

class Solution {
public:
	int repeatedStringMatch(string A, string B) {
		int count = 1;
		string temp = A;
		while (1)
		{
			if (A.find(B) != A.npos)
				break;
			else if (A.size()>B.size() + temp.size())
				return -1;
			{
				A += temp;
				++count;
			}
		}
		return count;
	}
};
