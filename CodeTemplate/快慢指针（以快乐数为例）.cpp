#include <bits/stdc++.h>

using namespace std;


/*
题目一：编写一个算法来判断一个数 n 是不是快乐数。
「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。如果 可以变为  1，
那么这个数就是快乐数。如果 n 是快乐数就返回 True ；不是，则返回 False 。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/happy-number
*/

/*
方法一：只要能够判断是否出现循环就行，出现循环则返回false
C++用map也能判断是否出现循环
*/

class Solution11 {
	int getNext(int num)
	{
		int ans = 0, mod;
		while (num)
		{
			mod = num % 10;
			ans += mod * mod;
			num /= 10;
		}
		return ans;
	}
public:
	bool isHappy(int n) {
		map<int, int> m;
		m.clear();

		while (n != 1)
		{
			n = getNext(n);
			if (m[n])
			{
				return false;
			}
			m[n]++;
		}
		return true;
	}
};


/*
方法二：快慢指针
*/
class Solution12 {
	int getNext(int num)
	{
		int ans = 0, mod;
		while (num)
		{
			mod = num % 10;
			ans += mod * mod;
			num /= 10;
		}
		return ans;
	}
public:
	bool isHappy(int n) {
		int slowRunner = n;
		int fasterRunner = getNext(n);

		while (fasterRunner != 1 && fasterRunner != slowRunner)
		{
			slowRunner = getNext(slowRunner);
			fasterRunner = getNext(getNext(fasterRunner));
		}
		return fasterRunner == 1;
	}
};



/*
题目二：寻找重复数
	给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），
可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
链接：https://leetcode-cn.com/problems/find-the-duplicate-number/solution/xun-zhao-zhong-fu-shu-by-leetcode-solution/
来源：力扣（LeetCode）
时间复杂度：O(N)
空间复杂度：O(1)
*/

class Solution21 {
public:
	int findDuplicate(vector<int>& nums) {
		int slow = 0, fast = 0;
		do {
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (slow != fast);

		slow = 0;

		while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[fast];
		}
		return slow;
	}
};