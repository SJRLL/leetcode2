
����һ��32λ������ n������Ҫ�ҵ���С��32λ���������� n �д��ڵ�λ����ȫ��ͬ��������ֵ����n�����������������32λ�������򷵻� - 1��

ʾ�� 1:

���� : 12
��� : 21
	 ʾ�� 2 :

 ���� : 21
  ��� : -1

//����˼·:���ڴ���INT_MAX������Ҫ���� - 1������

class Solution {
public:
	int nextGreaterElement(int n) {
		string temp = to_string(n); int flag = -1;
		for (int i = temp.size() - 1; i>0; --i)
		{
			if (temp[i]>temp[i - 1])
			{
				flag = i - 1;
				break;
			}
		}
		if (flag == -1)
			return -1;
		char max1 = '9';
		int maxin;
		for (int i = flag + 1; i<temp.size(); ++i)
		{
			if (temp[i]>temp[flag] && temp[i] <= max1)
			{
				max1 = temp[i];
				maxin = i;
			}
		}
		swap(temp[maxin], temp[flag]);
		sort(temp.begin() + flag + 1, temp.end());
		if (stoll(temp)>INT_MAX) return -1;
		return stoll(temp);
	}
};
