#include <bits/stdc++.h>

using namespace std;


/*
题目一：课程安排IV
题目链接：https://leetcode-cn.com/problems/course-schedule-iv/
方法：Floyd
参考：https://leetcode-cn.com/problems/course-schedule-iv/solution/floyd-by-over-lord/
*/


const int N = 110;
int INF = 0x3f3f3f3f;
int g[N][N];

class Solution {
private:
	void floyd(int n)
	{
		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
				}
			}
		}
	}
public:
	vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
		memset(g, INF, sizeof(g));
		for (vector<int> v : prerequisites)
		{
			g[v[0]][v[1]] = 1;
		}

		for (int i = 0; i < n; i++)
		{
			g[i][i] = 0;
		}

		floyd(n);

		vector<bool> ans;

		for (vector<int> v : queries)
		{
			ans.emplace_back(g[v[0]][v[1]] < INF);
		}

		return ans;
	}
};
