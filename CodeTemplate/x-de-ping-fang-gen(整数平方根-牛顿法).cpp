#include <bits/stdc++.h>
using namespace std;


/*
整数的平方根
作者：LeetCode
链接：https://leetcode-cn.com/problems/sqrtx/solution/x-de-ping-fang-gen-by-leetcode/
来源：力扣（LeetCode）
*/


/*
方法一：袖珍计算器方法
$\sqrt{x} =  {e}^{1/2 * ln (x)}$
这个方法会用到幂，可以直接这样求:
	$\sqrt{x} = {x}^{1/2}$
时间复杂度：O（1）
空间复杂度：O（1）
*/


/*
方法二：二分查找
在[0,x/2]之间必然存在一个数 c 使得 (c - 1)^2 < x < (c + 1)^2,则c为所求解
时间复杂度：O（logN）
空间复杂度：O（1）
*/


/*
方法三：牛顿法
$x_{k+1} = {1/2}[x_k + {x / x_k}]$
时间复杂度：O（logN）
空间复杂度：O（1）
*/
class Solution {
public:
	int mySqrt(int x) {
		if(x < 2)
		{
			return x;
		}

		double x0 = x;
		double x1 = (x0 + x / x0) / 2.0;
		while (abs(x0 - x1) >= 1)
		{
			x0 = x1;
			x1 = (x0 + x / x0) / 2.0;
		}
		return (int)x1;
	}


	/**
	 * 如果题目改成求三次根呢？
	 * xn+1=xn-f(xn)/f'(xn);
	 * f(x)=x^3-c;
	 * xn+1=xn-(x^3-c)/3x^2;
	 */
	int myThird(int x) {
		if (x < 2) return x;
		double x0 = x;
		double x1 = (2 * x0 + x / (x0 * x0)) / 3.0;
		while (abs(x1 - x0) >= 1e-8) {
			x0 = x1;
			x1 = (2 * x0 + x / (x0 * x0)) / 3.0;
		}
		return (int)x1;
	}


	//如果改成求n次根呢？
	int myN(int x, int n) {
		if (x < 2) return x;
		double x0 = x;
		double x1 = ((n - 1.0) / n) * x0 + x / (n * (pow(x0, n - 1)));
		while (abs(x1 - x0) >= 1e-8) {
			x0 = x1;
			x1 = ((n - 1.0) / n) * x0 + x / (n * (pow(x0, n - 1)));
		}
		return (int)x1;
	}
};
