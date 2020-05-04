����һ��Ԫ�ض���������������A �������� L �Լ� R(L <= R)��

���������ǿ����������Ԫ��������ڵ���L С�ڵ���R�������������

���� :
���� :
	A = [2, 1, 4, 3]
	L = 2
	R = 3
��� : 3
 ���� : ���������������� : [2], [2, 1], [3].

//����˼·��ά���������ݣ�ĿǰΪֹ���һ������R������Ӧ������(lastLargeThanRNumIndex)�����һ��λ������[L,R]�����ݵ�����(lastInTheRangeNumIndex)��

//��A[i] > Rʱ������lastLargeThanRNumIndex

//��A[i] < Lʱ�����lastInTheRangeNumIndex != -1 ���� lastInTheRangeNumIndex > lastLargeThanRNumIndex �����п��ܹ�������Ҫ�������, ��ʽΪ��

A[(lastLargeThanRNumIndex + 1)...lastInTheRangeNumIndex...i]��

//A[i]λ��[L, R]�м�ʱ������lastInTheRangeNumIndex������ܹ�������Ҫ������䣬��ʽΪA[(lastLargeThanRNumIndex + 1)...i]��

class Solution {
public:
	int numSubarrayBoundedMax(vector<int> &A, int L, int R) {
		int ans = 0;
		int lastLargeThanRNumIndex = -1;
		int lastInTheRangeNumIndex = -1;
		for (int i = 0; i < A.size(); ++i) 
		{
			if (A[i] > R) 
			{
				lastLargeThanRNumIndex = i;
			}
			else if (A[i] < L) 
			{
				if (lastInTheRangeNumIndex != -1 && lastInTheRangeNumIndex > lastLargeThanRNumIndex) 
				{
					ans += lastInTheRangeNumIndex - lastLargeThanRNumIndex;
				}
			}
			else 
			{
				lastInTheRangeNumIndex = i;
				ans += i - lastLargeThanRNumIndex;
			}
		}
		return ans;
	}
};

