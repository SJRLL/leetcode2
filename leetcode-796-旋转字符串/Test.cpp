给定两个字符串, A 和 B。

A 的旋转操作就是将 A 最左边的字符移动到最右边。 例如, 若 A = 'abcde'，在移动一次之后结果就是'bcdea' 。如果在若干次旋转操作之后，A 能变成B，那么返回True。

示例 1:
输入 : A = 'abcde', B = 'cdeab'
输出 : true

	 示例 2 :
 输入 : A = 'abcde', B = 'abced'
  输出 : false

//解题思路:算是字符串循环左移的变种问题。循环左移还是用的三次反转，写了很多遍了，快背下来了哈哈哈。
//但是不同点是循环左移的位置要自己判断，遍历A，当A的字符与B[0]相同时，此时的循环左移才有可能相同，所以要判断下A[i]与B[0]，
//减少左移的操作。左移后的A若与B相等，那么直接返回TRUE；遍历后没有返回值，则hd返回FALSE.

	 class Solution {
	 public:
		 bool rotateString(string A, string B) {
			 if (A.length() == 0 && B.length() == 0)
			 {
				 return true;
			 }
			 char b = B[0];
			 for (int i = 0; i<A.length(); i++)
			 {
				 if (A[i] == b)
				 {
					 if (reverse_string(A, i) == B)
					 {
						 return true;
					 }
				 }
			 }
			 return false;
		 }

		 string reverse_string(string s, int n)
		 {
			 s = reverse_single(s, 0, n - 1);
			 s = reverse_single(s, n, s.length() - 1);
			 return reverse_single(s, 0, s.length() - 1);
		 }

		 string reverse_single(string s, int from, int to)
		 {
			 char temp;
			 while (from<to)
			 {
				 temp = s[from];
				 s[from++] = s[to];
				 s[to--] = temp;
			 }
			 return s;
		 }
	 };
