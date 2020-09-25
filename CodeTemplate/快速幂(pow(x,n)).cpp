/*
题目：求Pow(x, n)
链接：https ://leetcode-cn.com/problems/powx-n/solution/powx-n-by-leetcode-solution/
来源：力扣（LeetCode）
*/


//快速幂+迭代
class Solution {
	double quickMul(double x, long long N)
	{
		double ans = 1.0;
		double x_contribution = x;
		while (N > 0)
		{
			if (N & 1)
			{
				ans *= x_contribution;
			}
			x_contribution *= x_contribution;
			N >>= 1;
		}
		return ans;
	}
public:
	double myPow(double x, int n) {
		long long N = n;
		return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
	}
};
