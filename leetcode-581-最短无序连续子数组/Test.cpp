����һ���������飬����ҪѰ��һ�������������飬���������������������������ô�������鶼���Ϊ��������

���ҵ���������Ӧ����̵ģ���������ĳ��ȡ�

ʾ�� 1:

���� : [2, 6, 4, 8, 10, 9, 15]
��� : 5
 ���� : ��ֻ��Ҫ��[6, 4, 8, 10, 9] ��������������ô���������Ϊ��������

//����˼·��
����ջ
�����������������ջ���ҳ���ʼ����û�г�ջ��������� l
��������������ݼ�ջ���ҳ���ʼ����û�г�ջ����С���� r
�м������Ҫ�������С������

int findUnsortedSubarray(vector<int>& nums)
{
	stack<int> st;
	int l = nums.size() - 1;
	int r = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		while (!st.empty() && nums[st.top()] > nums[i])
		{
			l = min(l, st.top());
			st.pop();
		}
		st.push(i);
	}
	st = stack<int>();
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		while (!st.empty() && nums[st.top()] < nums[i])
		{
			r = max(r, st.top());
			st.pop();
		}
		st.push(i);
	}
	return (r > l) ? r - l + 1 : 0;
}
