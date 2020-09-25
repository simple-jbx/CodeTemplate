#include<bits/stdc++.h>

using namespace std;


/*
题目一：每日温度
题目链接：https://leetcode-cn.com/problems/daily-temperatures/
*/

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		stack<int> s;
		int tsize = T.size();
		vector<int> ans(tsize, 0);

		for (int i = 0; i < tsize; i++)
		{
			while (!s.empty() && T[i] > T[s.top()])
			{
				ans[s.top()] = i - s.top();
				s.pop();
			}
			s.push(i);
		}
		return ans;
	}
};
