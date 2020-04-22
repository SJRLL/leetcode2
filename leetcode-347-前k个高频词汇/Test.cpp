
����һ���ǿյ��������飬�������г���Ƶ��ǰ k �ߵ�Ԫ�ء�

ʾ�� 1:

���� : nums = [1, 1, 1, 2, 2, 3], k = 2
��� : [1, 2]
	 ʾ�� 2 :

 ���� : nums = [1], k = 1
  ��� : [1]

��������Ͱ���� ʱ�临�Ӷ�O(N)
vector<int> topKFrequent(vector<int>& nums, int k) {

	//ͳ�ƴ���
	unordered_map<int, int> m;

	for (int i = 0; i < nums.size(); ++i)
	{
		++m[nums.at(i)];
	}

	//ʹ�ö�ά����  ͳ�ƴ�����Ϊ��һά�����ͳ�ƴ�������ͬ����ֵ׷�ӵ�Ͱ�У�
	vector<vector<int>> buckets(nums.size() + 1);

	for (auto iter = m.begin(); iter != m.end(); ++iter)
	{
		buckets.at(iter->second).push_back(iter->first);
	}

	//��buckets��ǰk����ƵԪ�ط���res��
	vector<int> res(k);
	int count = 0;
	for (int i = buckets.size() - 1; i >= 0; --i)
	{
		for (int j = 0; j < buckets.at(i).size(); ++j)
		{
			res.at(count) = buckets.at(i).at(j);
			++count;
			if (count == k)
				return res;
		}
	}

	return res;
}
