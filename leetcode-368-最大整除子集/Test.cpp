����һ�������ظ�����������ɵļ��ϣ��ҳ��������������Ӽ����Ӽ�������һ��(Si��Sj) ��Ҫ���㣺Si % Sj = 0 �� Sj % Si = 0��

����ж��Ŀ���Ӽ������������κ�һ�����ɡ�



ʾ�� 1:

���� : [1, 2, 3]
��� : [1, 2](��Ȼ, [1, 3] Ҳ��ȷ)
	 ʾ�� 2 :

 ���� : [1, 2, 4, 8]
  ��� : [1, 2, 4, 8]

//����˼·
1.Ԫ�ش�С��������
2.��������ͼ�� �����ǰԪ��i���Ա�Ԫ��j���� ����һ������ߣ�i->j�� ����next�����¼��ǰ·������һ������
3.��������ͼ�������ҳ��·��

 class Solution {
	 public:
		 //DAG�·������ ����һ������ͼ Ȼ���ҵ�ͼ�е��·�� 21��34
		 vector<vector<int> > G;
		 vector<int> dp;
		 vector<int> next, ans;
		 vector<int> largestDivisibleSubset(vector<int>& nums) 
		 {
			 int len = nums.size();
			 if (len == 0) 
				 return vector<int>();
			 G = vector<vector<int> >(len, vector<int>(len, 0));
			 dp = vector<int>(len, 1);
			 next = vector<int>(len, -1);
			 sort(nums.begin(), nums.end());
			 //��������ͼ
			 for (int i = 0; i<len; ++i)
			 {
				 for (int j = i + 1; j<len; ++j)
				 {
					 if (nums[j] % nums[i] == 0)
					 {
						 G[i][j] = 1;
					 }
				 }
			 }
			 int res = 0, st = 0;
			 for (int k = 0; k<len; ++k)
			 {
				 int tmp = DP(k, len);
				 if (tmp>res)
				 {
					 res = tmp;
					 st = k;
				 }
			 }
			 for (int t = st; t != -1;)
			 {
				 ans.push_back(nums[t]);
				 t = next[t];
			 }
			 return ans;
		 }

		 int DP(int i, int n)
		 { //dp[i] ��¼��i�Ŷ���������ܵ�������·��
			 if (dp[i] != 1) 
				 return dp[i];
			 int maxn = 1;
			 for (int j = i + 1; j<n; ++j){//�������б�
				 if (G[i][j] == 1)
				 {
					 int tmp = DP(j, n) + 1;
					 if (tmp>maxn)
					 {
						 maxn = tmp;
						 next[i] = j;
					 }
				 }
			 }
			 dp[i] = maxn;
			 return dp[i];
		 }
};

