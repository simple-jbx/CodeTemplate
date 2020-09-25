#include <bits/stdc++.h>

using namespace std;
/*
双指针专题
题目一：容器装最多水
题目二：数对和
*/

/*
题目一：给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，
垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容
纳最多的水。
说明：你不能倾斜容器，且 n 的值至少为 2。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water
*/
class SolutionContainerWithMostWater{
public:
	int maxArea(vector<int>& height) {
		int num = (int)height.size(), l = 0, r = num - 1, ans = 0;

		while (l < r)
		{
			if (height[l] < height[r])
			{
				ans = max(ans, height[l] * (r - l));
				l++;
			}
			else
			{
				ans = max(ans, height[r] * (r - l));
				r--;
			}
		}
		return ans;
	}
};




/*
题目二：数对和
设计一个算法，找出数组中两数之和为指定值的所有整数对。一个数只能属于一个数对。
e.g.输入: nums = [5,6,5,6], target = 11
	输出: [[5,6],[5,6]]
作者：simple-081230
链接：https://leetcode-cn.com/problems/pairs-with-sum-lcci/solution/shu-dui-he-map-shuang-zhi-zhen-by-simple-104/
来源：力扣（LeetCode）
*/

//方法一：哈希
class SolutionPairsWithSumLcci1 {
public:
	vector<vector<int> > pairSums(vector<int>& nums, int target) {
		vector<vector<int> > ans;
		map<int, int> m;

		int n = (int)nums.size();

		for (int i = 0; i < n; i++)
		{
			m[nums[i]]++;
		}

		for (int i = 0; i < n; i++)
		{
			if (m[nums[i]])
			{
				m[nums[i]]--;
				if (m[target - nums[i]])
				{
					ans.push_back({ nums[i], target - nums[i] });
					m[target - nums[i]]--;
				}
			}
		}
		return ans;
	}
};


//方法二：双指针
class SolutionPairsWithSumLcci2 {
public:
	vector<vector<int> > pairSums(vector<int>& nums, int target) {
		vector<vector<int> > ans;

		ios::sync_with_stdio(false);

		sort(nums.begin(), nums.end());

		int l = 0, r = (int)nums.size() - 1;

		while (l < r)
		{
			if (nums[l] + nums[r] == target)
			{
				ans.push_back({ nums[l++], nums[r--] });
			}
			else if (nums[l] + nums[r] > target)
			{
				r--;
			}
			else
			{
				l++;
			}
		}
		return ans;
	}
};


/*
题目三：三数之和
题目链接：
*/
class Solution3Sum {
public:
	vector<vector<int> > threeSum(vector<int>& nums) {
		int nsize = nums.size();
		int head = 0;
		vector<vector<int> > ans;
		int left = 1, right = nsize - 1;
		sort(nums.begin(), nums.end());
		vector<int> v(3, 0);
		while (head <= nsize - 3)
		{
			if (nums[head] > 0)
			{
				break;
			}

			if (head > 0 && nums[head] == nums[head - 1])
			{
				head++;
				continue;
			}

			int n = 0 - nums[head];
			int mid = nums[left] + nums[right];
			left = head + 1;
			right = nsize - 1;
			while (left < right)
			{
				mid = nums[left] + nums[right];
				if (mid == n)
				{
					v[0] = nums[head];
					v[1] = nums[left];
					v[2] = nums[right];
					ans.push_back({ nums[head], nums[left], nums[right] });
					while (left < right && nums[left] == nums[++left]);
					while (left < right && nums[right] == nums[--right]);
				}
				else if (mid > n)
				{
					while (left < right && nums[right] == nums[--right]);
				}
				else
				{
					while (left < right && nums[left] == nums[++left]);
				}
			}
			head++;
		}
		return ans;
	}
};


