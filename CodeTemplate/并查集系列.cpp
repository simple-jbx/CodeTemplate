#include <bits/stdc++.h>

using namespace std;

/*
题目：等式方程的可满足性
链接：https://leetcode-cn.com/problems/satisfiability-of-equality-equations/solution/deng-shi-fang-cheng-de-ke-man-zu-xing-by-leetcode-/
来源：力扣（LeetCode）
*/


class UnionFind {
private:
	vector<int> parent;

public:
	UnionFind()
	{
		parent.resize(26);
		//递增赋值 parent[i] = i
		iota(parent.begin(), parent.end(), 0);
	}

	int findParent(int index)
	{
		if (index == parent[index])
		{
			return index;
		}

		parent[index] = findParent(parent[index]);
		return parent[index];
	}

	void unionIte(int index1, int index2)
	{
		parent[findParent(index1)] = findParent(index2);
	}

};


class Solution {
public:
	bool equationsPossible(vector<string>& equations) {
		UnionFind uf;
		int index1, index2;
		for (const string &str : equations)
		{
			if (str[1] == '=')
			{
				index1 = str[0] - 'a';
				index2 = str[3] - 'a';
				uf.unionIte(index1, index2);
			}
		}

		for (const string &str : equations)
		{
			if (str[1] == '!')
			{
				index1 = str[0] - 'a';
				index2 = str[3] - 'a';
				if (uf.findParent(index1) == uf.findParent(index2))
				{
					return false;
				}
			}
		}
		return true;
	}
};
