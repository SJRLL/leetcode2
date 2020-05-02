���������ַ���, A �� B��

A ����ת�������ǽ� A ����ߵ��ַ��ƶ������ұߡ� ����, �� A = 'abcde'�����ƶ�һ��֮��������'bcdea' ����������ɴ���ת����֮��A �ܱ��B����ô����True��

ʾ�� 1:
���� : A = 'abcde', B = 'cdeab'
��� : true

	 ʾ�� 2 :
 ���� : A = 'abcde', B = 'abced'
  ��� : false

//����˼·:�����ַ���ѭ�����Ƶı������⡣ѭ�����ƻ����õ����η�ת��д�˺ܶ���ˣ��챳�����˹�������
//���ǲ�ͬ����ѭ�����Ƶ�λ��Ҫ�Լ��жϣ�����A����A���ַ���B[0]��ͬʱ����ʱ��ѭ�����Ʋ��п�����ͬ������Ҫ�ж���A[i]��B[0]��
//�������ƵĲ��������ƺ��A����B��ȣ���ôֱ�ӷ���TRUE��������û�з���ֵ����hd����FALSE.

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
