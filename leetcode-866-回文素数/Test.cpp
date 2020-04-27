求出大于或等于 N 的最小回文素数。

回顾一下，如果一个数大于 1，且其因数只有 1 和它自身，那么这个数是素数。

例如，2，3，5，7，11 以及 13 是素数。

回顾一下，如果一个数从左往右读与从右往左读是一样的，那么这个数是回文数。

例如，12321 是回文数。



示例 1：

输入：6
输出：7
示例 2：

输入：8
输出：11
示例 3：

输入：13
输出：101


解题思路：
根据提示，答案长度最长为 9 位。

暴力法会超时，因此可以先构建回文数，再判断是不是素数。

构建回文数可以从 N 的当前长度开始：比如 N = 123, 可以从长度为 3 的 101 开始构建。

构建回文数可以忽略偶数长度，因为偶数长度的回文数，奇数位上数字之和 = 偶数位上数字之和，是11的倍数，所以不是素数。
比如 131131, 1 + 1 + 3 = 3 + 1 + 1, 所以 131131 是 11 的倍数，不是素数。

构建回文数可以从外到内，从小到大构建，这样可以保证结果递增。从外到内递归实现。比如长度为5 :
10001, 11011, 11111, 11211, ..., 11911,
12021, 12121, ..., 12921,
......
19091, 19191, ..., 19991,
20002 //忽略
30003, 31013, ......
......
99999

最外层数字肯定不是 0, 因为最高位不是 0; 如果个位的数字是 2 的倍数或者是 5, 那肯定不是素数，可以忽略。


vector<int> digits(int n) 
{
	vector<int> nums;
	while (n > 0) 
	{
		nums.push_back(n % 10);
		n /= 10;
	}
	reverse(nums.begin(), nums.end());
	return nums;;
}

bool isPrime(int n) {
	if (n < 2) return false;
	int t = sqrt(n);
	for (int i = 2; i <= t; ++i)
	{
		if (n % i == 0) return false;
	}
	return true;
}
// 回文数生成器
class PalindromeGenerator {
public:
	long start;
	long k;
	queue<long> nums;
	PalindromeGenerator(long s) : start(s) 
	{
		vector<int> v = digits(start);
		k = v.size();
		long beg = 0;
		for (int i = 0; i <= (k - 1) / 2; ++i) 
		{
			beg *= 10;
			beg += v[i];
		}
		generateWithLenK(k, beg);
		++k;
	};
	void generateWithLenK(long k, long beg = 0) {
		long m = (k - 1) / 2;
		beg = max(beg, (long)pow(10, m));
		long end = pow(10, m + 1);
		for (int i = beg; i < end; ++i) 
		{
			long n = i;
			long t = i;
			if (k % 2 == 1) t /= 10;
			while (t > 0) 
			{
				n *= 10;
				n += t % 10;
				t /= 10;
			}
			if (n >= start) 
			{
				nums.push(n);
			}
		}
	}
	long next() {
		if (nums.empty()) generateWithLenK(k++);
		long res = nums.front();
		nums.pop();
		return res;
	}
};

class Solution {
public:

	int primePalindrome(int N) {
		auto pg = PalindromeGenerator(N);
		while (true) 
		{
			int n = pg.next();
			if (isPrime(n)) return n;
		}
		return 0;
	}
};
