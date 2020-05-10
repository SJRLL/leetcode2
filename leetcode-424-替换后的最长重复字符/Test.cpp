给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，总共可最多替换 k 次。在执行上述操作后，找到包含重复字母的最长子串的长度。

注意 :
字符串长度 和 k 不会超过 104。

示例 1 :

输入 :
   s = "ABAB", k = 2

输出 :
   4

解释 :
   用两个'A'替换为两个'B', 反之亦然。
   示例 2 :

输入 :
   s = "AABABBA", k = 1

输出 :
   4

解释 :
   将中间的一个'A'替换为'B', 字符串变为 "AABBBBA"。
   子串 "BBBB" 有最长重复字母, 答案为 4。

//解题思路：
关于maxCount的解释：
maxcount + k的逻辑含义是滑动窗口的最大值，因此maxcount表示的是最大窗口，而不是当前窗口内的最大重复字符个数。
因为我们只对最长有效的子字符串感兴趣，所以我们的滑动窗口不需要收缩，即使窗口可能覆盖无效的子字符串。
因此当right - left + 1>maxcount + k时
1）左边出一个，右边进一个，对窗口进行平移
2）只在新字符的计数超过历史最大计数(来自覆盖有效子字符串的前一个窗口)时才增长窗口，即更新maxcount。
也就是说，我们不需要精确的当前窗口的最大计数; 我们只关心最大计数是否超过历史最大计数; 这只会因为新字符而发生。

class Solution {
public:
	int characterReplacement(string s, int k) {

		int left = 0;
		int maxcount = 0;
		map<int, int> count;

		for (int i = 0; i < s.size(); i++){
			int rindex = s[i] - 'A';
			count[rindex]++;
			maxcount = max(maxcount, count[rindex]);
			if (i - left + 1>maxcount + k){
				int lindex = s[left] - 'A';
				count[lindex]--;
				left++;
			}
		}

		return s.size() - left;
	}
};

