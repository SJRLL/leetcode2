
����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��

ʾ�� :

���� : [0, 1, 0, 3, 12]
��� : [1, 3, 12, 0, 0]

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int lastNozero = 0;
		for (int i = 0; i<nums.size(); ++i)
		{
			if (nums[i] != 0)
			{
				nums[lastNozero++] = nums[i];
			}
		}

		for (int i = lastNozero; i<nums.size(); ++i)
		{
			nums[i] = 0;
		}
	}
};