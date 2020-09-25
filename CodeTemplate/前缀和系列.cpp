#include<bits/stdc++.h>

using namespace std;

/*
题目一：和可被 K 整除的子数组
给定一个整数数组 A，返回其中元素之和可被 K 整除的（连续、非空）子数组的数目。

例如：
	输入：A = [4,5,0,-2,-3,1], K = 5
	输出：7
	解释：
	有 7 个子数组满足其元素之和可被 K = 5 整除：
	[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subarray-sums-divisible-by-k
*/

/*
方法一：哈希表 + 逐一统计
通常，涉及连续子数组问题的时候，使用前缀和来解决。
*/
class Solution {
public:
	int subarraysDivByK(vector<int>& A, int K) {
		unordered_map<int, int> record{ {0, 1} };
		int ans = 0, mod = 0;
		for (auto n : A)
		{
			mod += n;
			mod = (mod % K + K) % K;
			if (record.count(mod))
			{
				ans += record[mod];
			}
			record[mod]++;
		}
		return ans;
	}
};
