#include <bits/stdc++.h>

using namespace std;


/*
题目一：数组中数字出现的次数
	一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
	请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
	2 <= nums.size() <= 10000
作者：LeetCode - Solution
链接：https ://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/solution/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-by-leetcode/
来源：力扣（LeetCode）
*/

/*
方法一： 按照题目要求如果数组中只有两个元素直接返回即可
	先将数组排序
	将数组首尾特殊处理，如果第一个元素与第二个元素不相等则第一个元素为答案中的一个元素
	同理，若最后一个元素与倒数第二个元素不相等，则最后一个元素为所需答案中的一个
	剩下的元素如果与它相邻的两个元素都不相等则改元素为所需答案中的一个
	也能过，但耗时约为方法二的两倍
时间复杂度：O（NlogN） 快排（O（NlogN）） 遍历一遍数组（O（N））
空间复杂度：O（1） 只需要记录下所需答案即可
*/
class Solution11 {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		int n = (int)nums.size();

		if (n == 2)
		{
			return nums;
		}

		sort(nums.begin(), nums.end());

		vector<int> ans;
		ans.clear();

		if (nums[0] != nums[1])
		{
			ans.push_back(nums[0]);
		}

		if (nums[n - 1] != nums[n - 2])
		{
			ans.push_back(nums[n - 1]);
		}

		for (int i = 1; i < n - 1; i++)
		{
			if (ans.size() == 2)
			{
				return ans;
			}

			if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
			{
				ans.push_back(nums[i]);
			}
		}
		return ans;
	}
};


/*
方法二：异或分组
	两个相同的数异或结果为0，易知，对数组中所有数异或所得结果（ret）即为不重复的那两个数的异或结果
	要想找出最终的两个数字，还需要将整个数组分成两组，两个只出现一次的数字在不同的组中，相同的
数字出现在同一组中。
	把数字写成二进制形式｛x_k,x_{k-1},...,x_3,x_2,x_1,x_0｝，其中x_i 为0 or 1，任选一个不为0的
x_i，即按照第i位对原来的序列进行分组，首先ret的第i位为1说明两个只出现一次的数字第i位不相同，其次按照
这种分法两个相同的数字必然会被分在同一个组里。
*/


class Solution12 {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		int ret = 0;

		for (int n : nums)
		{
			ret ^= n;
		}

		int div = 1;
		while ((div & ret) == 0)
		{
			div <<= 1;
		}

		int a = 0, b = 0;
		for (int n : nums)
		{
			if (div & n)
			{
				a ^= n;
			}
			else
			{
				b ^= n;
			}
		}
		return vector<int> {a, b};
	}
};
