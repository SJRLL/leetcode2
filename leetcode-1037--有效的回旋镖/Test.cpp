�����ڶ���Ϊһ�������㣬��Щ�������ͬ�Ҳ���һ��ֱ���ϡ�

����ƽ������������ɵ��б��ж���Щ���Ƿ���Թ��ɻ����ڡ�



ʾ�� 1��

���룺[[1, 1], [2, 3], [3, 2]]
�����true
ʾ�� 2��

���룺[[1, 1], [2, 2], [3, 3]]
�����false

���ȷ�ĸ����Ϊ0����θ������겻��ȣ���б�ʲ��ȣ�ע������ʱ��double������true��

class Solution {
public:
	bool isBoomerang(vector<vector<int>>& points) {
		bool f = 0;
		double k1 = 0, k2 = 0;
		if (points[0][1] - points[1][1] == 0)
		{
			k1 = INT_MAX;
		}

		if (points[1][1] - points[2][1] == 0)
		{
			k2 = INT_MAX;
		}
		if (points[0] != points[1] && points[0] != points[2] && points[2] != points[1])
		{
			if (k1 != INT_MAX) k1 = (double)
				(points[0][0] - points[1][0]) / (points[0][1] - points[1][1]);
			if (k2 != INT_MAX) k2 = (double)
				(points[1][0] - points[2][0]) / (points[1][1] - points[2][1]);
			if (k1 != k2) f = 1;
		}
		return f;
	}
};
