二进制手表顶部有 4 个 LED 代表小时（0 - 11），底部的 6 个 LED 代表分钟（0 - 59）。

每个 LED 代表一个 0 或 1，最低位在右侧。
例如，上面的二进制手表读取 “3 : 25”。

给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间。

案例 :

输入 : n = 1
返回 : ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]

//解题思路：简单粗暴，首先是确定好hour和minute在对应的light时候的时间，然后一一去对应上

class Solution {
public:
	vector<string> readBinaryWatch(int num) {
		int h = 0;
		vector<string> res;
		for (h = 0; h <= num; h++){
			int m = num - h;
			auto hou = hour(h);
			auto mins = minute(m);
			string time = "";
			for (auto i : hou){

				for (auto j : mins){
					time = to_string(i) + ":";
					if (j<10){
						time += "0";
					}
					time += to_string(j);
					res.push_back(time);
				}
			}
		}
		return res;
	}
	vector<int> hour(int light){
		switch (light){
		case 0:
			return{ 0 };
		case 1:
			return{ 1, 2, 4, 8 };
		case 2:
			return{ 3, 5, 6, 9, 10 };
		case 3:
			return{ 7, 11 };
		default:
			return{};
		}
	}
	vector<int> minute(int light){
		switch (light){
		case 0:
			return{ 0 };
		case 1:
			return{ 1, 2, 4, 8, 16, 32 };
		case 2:
			return{ 3, 5, 6, 9, 10, 12, 17, 18, 20, 24, 33, 34, 36, 40, 48 };
		case 3:
			return{ 7, 11, 13, 14, 19, 21, 22, 25, 26, 28, 35, 37, 38, 41, 42, 44, 49, 50, 52, 56 };
		case 4:
			return{ 15, 23, 27, 29, 30, 39, 43, 45, 46, 51, 53, 54, 57, 58 };
		case 5:
			return{ 31, 47, 55, 59 };
		default:
			return{};
		}
	}
};

