给定一个字符串来代表一个学生的出勤记录，这个记录仅包含以下三个字符：

'A' : Absent，缺勤
'L' : Late，迟到
'P' : Present，到场
如果一个学生的出勤记录中不超过一个'A'(缺勤)并且不超过两个连续的'L'(迟到), 那么这个学生会被奖赏。

你需要根据这个学生的出勤记录判断他是否会被奖赏。

示例 1 :

输入 : "PPALLP"
 输出 : True
	  示例 2 :

  输入 : "PPALLL"
   输出 : False

//解题思路：先在首尾添加到场'P',字符串长度增加2，然后从1开始遍历字符串，统计A 的个数以及是否有连续3个及以上的L，最后判断即可~~

public:
	bool checkRecord(string s) {
		s.insert(s.begin(), 'P');
		s.push_back('P');
		int n = s.size();
		int A_num = 0;
		int P_tag = 0;
		for (int i = 1; i < n - 1; ++i)
		{
			if (s[i] == 'A')
				A_num++;
			if (s[i] == 'L' && s[i - 1] == 'L' && s[i + 1] == 'L')
				P_tag = 1;
		}
		return (A_num <= 1 && P_tag == 0) ? true : false;
	}
};

