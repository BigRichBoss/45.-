// 45.跳跃游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
//找到最大的数就行。这个数的长度能到最后的位置的距离
using namespace std;
class Solution {
public:
	// bool static com(pair<int,int>&A,pair<int,int>&B)
	// {
	//     return A.second<=B.second;
	// }
	int jump(vector<int>& nums) {
		int step = 0;
		// int cur=0;
		for (int i = 0; i < nums.size();)
		{
			map<int, int> mp;
			for (int j = i,index=0; index<= nums[i]&&j<nums.size();index++ ) //找到这一步中最大的区间，(j+nums[j])得到最大值，即所求；
			{
				mp.emplace(j, j + nums[j]);
				if (j + nums[j] >= nums.size() - 1)
				{
					if(j!=i)  ++step;
					
					break;
				}
				j++;
			}
			//
		   //auto iter= max_element(mp.begin(),mp.begin(),com);
			auto x = std::max_element(mp.begin(), mp.end(),
				[](const pair<int, int>& p1, const pair<int, int>& p2) {
				return p1.second < p2.second; });
			int pos = x->first;
			if (i != pos) ++step;
			i = pos;
			//  cur=
			//++step;
			//if (x->second >= nums.size() - 1) break;
		}
		return step+1;

	}
};

int main()
{
	vector<int>nums = { 3,2,1 };
	Solution ss;
	int res=ss.jump(nums);
	std::cout << res << endl;
	system(0);
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
