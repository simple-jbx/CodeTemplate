#include <bits/stdc++.h>

using namespace std;


/**
题目一：最长上升子序列（LIS）
方法一：动态规划
时间复杂度 O(n^2)
空间复杂度 O(n)
*/
class Solution11 {
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = (int)nums.size(), ans = 0;

		//长度为0 or 1 则最长上升序列就为0 or 1
		if (n < 2)
		{
			return n;
		}

		vector<int> num(n, 0); //状态数组
		for (int i = 0; i < n; i++)
		{
			num[i] = 1;
			for (int j = 0; j < i; j++)
			{
				if (nums[j] < nums[i])
				{
					num[i] = max(num[i], num[j]+1);
				}
			}
		}
		return *max_element(num.begin(), num.end());
	}
};



/*
方法二：贪心+二分
时间复杂度 O(nlog(n))
空间复杂度 O(n)
详细解释见：https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode-soluti/
要使得上升子序列尽可能的长，就要使序列上升的尽可能慢，也就是每次在上升序列最后加上的那个数最小
维护一个数组num[]，表示长度为i的上升序列的末尾最小值为num[i]，易知num关于i单调递增
遍历nums[]的值，并更新数组num[]和长度ans的值。如果nums[i] > num[ans], 则num[++len] = nums[i]
否则二分(由于num[]数组单调性)找num[]中满足num[j-1] < nums[i] < num[j]的下标j，并更新num[j] = nums[i]
*/
class Solution12 {
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = (int)nums.size(), ans = 1;
		if (n == 0)
			return 0;
		vector<int> num(n + 1, 0);
		num[1] = nums[0];
		for (int i = 1; i < n; i++)
		{
			if (nums[i] > num[ans])
			{
				num[++ans] = nums[i];
			}
			else
			{
				int l = 1, r = ans, pos = 0, mid;
				//如果都找不到说明nums[i] < nums[0-(i-1)],此时需更新num[1],所以pos=0
				while (l <= r)
				{
					mid = (l + r) >> 1;
					if (num[mid] < nums[i])
					{
						pos = mid;
						l = mid + 1;
					}
					else
					{
						r = mid - 1;
					}
				}
				num[pos + 1] = nums[i];
			}
		}
		return ans;
	}
};
