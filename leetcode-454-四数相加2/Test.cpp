给定四个包含整数的数组列表 A, B, C, D, 计算有多少个元组(i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。

为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 - 228 到 228 - 1 之间，最终结果不会超过 231 - 1 。

例如 :

输入 :
	A = [1, 2]
	B = [-2, -1]
	C = [-1, 2]
	D = [0, 2]

输出 :
   2

解释 :
两个元组如下 :
	   1. (0, 0, 0, 1)->A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
	   2. (1, 1, 0, 0)->A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

	//思路：
	   AB两个数组，CD两个数组分别做笛卡尔积生成两个大小为n ^ 2的数组
	   对新数组进行排序
	   扫描其中一个新数组，再用二分查找对应值。
	   优化：
	   用pair存储数据，第一元代表数值，第二元代表个数
	   二分查找到对应数值后结果加上两个值数量的乘积
	   时间复杂度：O(n ^ 2log(n ^ 2))

   class Solution {
   public:
	   int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		   int n = A.size();
		   if (!n) return 0;
		   vector<int> E, F;
		   for (int i = 0; i<n; ++i)
		   for (int j = 0; j<n; ++j)
			   E.push_back(A[i] + B[j]);
		   for (int i = 0; i<n; ++i)
		   for (int j = 0; j<n; ++j)
			   F.push_back(C[i] + D[j]);
		   n *= n;
		   sort(E.begin(), E.end());
		   sort(F.begin(), F.end());
		   vector<pair<int, int>> a, b;
		   int cnt = 1;
		   for (int i = 1; i <= n; ++i)
		   {
			   if (i == n || E[i] != E[i - 1])
			   {
				   pair<int, int> t(E[i - 1], cnt);
				   a.push_back(t);
				   cnt = 1;
			   }
			   else ++cnt;
		   }
		   for (int i = 1; i <= n; ++i)
		   {
			   if (i == n || F[i] != F[i - 1])
			   {
				   pair<int, int> t(F[i - 1], cnt);
				   b.push_back(t);
				   cnt = 1;
			   }
			   else ++cnt;
		   }
		   int ans = 0;
		   for (int i = 0; i<a.size(); ++i)
		   {
			   int l = 0, r = b.size() - 1;
			   int m;
			   while (l <= r)
			   {
				   m = (r - l) / 2 + l;
				   if (b[m].first == -a[i].first) break;
				   else if (b[m].first < -a[i].first) l = m + 1;
				   else r = m - 1;
			   }
			   if (b[m].first == -a[i].first) ans += b[m].second * a[i].second;
		   }
		   return ans;
	   }
   };
