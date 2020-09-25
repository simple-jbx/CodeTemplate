/*
题目一：乘积最大子数组
链接：https ://leetcode-cn.com/problems/maximum-product-subarray/solution/cheng-ji-zui-da-zi-shu-zu-by-leetcode-solution/
来源：力扣（LeetCode）
*/


//动态规划
/*
	不能单纯只考虑前一个位置的最大值，因为数组中存在负值，因此对于当前位置为正数的，则希望前一个位置所得积为正且最大，如果当前
位置为负数，则希望前一个位置所得积为负且最小。因而需要对正负性进行讨论,然后得到两个状态转移方程。
*/
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		vector<int> minF(nums), maxF(nums);
		int n = nums.size();
		for (int i = 1; i < n; i++)
		{
			minF[i] = min(minF[i], min(minF[i - 1] * nums[i], maxF[i - 1] * nums[i]));
			maxF[i] = max(maxF[i], max(minF[i - 1] * nums[i], maxF[i - 1] * nums[i]));
		}
		return *max_element(maxF.begin(), maxF.end());
	}
};
