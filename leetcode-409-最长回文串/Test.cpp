给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。

在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。

注意 :
假设字符串的长度不会超过 1010。

示例 1 :

输入 :
   "abccccdd"

输出 :
   7

解释 :
   我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。

   //解题思路
   创建哈希表统计出现个数为偶数的字符以及出现次数大于一且为奇数的字符，
   先将其字符数全部加起来（其中出现次数为奇数的减一当作出现次数为偶数的字符，因为最大长的回文串如果有条件的话都会包含一个单独的字符）
   ，最后比较一下统计总和与字符串总和是否相等，不相等则说明必定有一个单独的字符，所以返回统计总和再加一的值，否则直接返回统计的总和

class Solution {
public:
	int longestPalindrome(string s) {
		int size = s.size();
		if (size == 0 || size == 1){
			return size;
		}
		unordered_map<char, int> map;
		int sum = 0;
		for (int i = 0; i < size; i++){
			if (map.count(s[i]) != 1){
				map.insert(make_pair(s[i], 1));
			}
			else{
				map[s[i]]++;
			}
		}

		for (int j = 0; j < size; j++){
			if (map[s[j]] > 1){
				if (map[s[j]] % 2 == 0){
					sum = sum + map[s[j]];
				}
				else if (map[s[j]] % 2 == 1){
					sum = sum + map[s[j]] - 1;
				}
				map.erase(s[j]);
			}
		}

		if (sum < size){
			return sum + 1;
		}
		else{
			return sum;
		}
	}
};

