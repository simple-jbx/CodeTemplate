#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
前序（根-左-右）遍历
*/
class PreorderSolution {
private:
	void order(vector<int>& porder, TreeNode* root)
	{
		if (root == nullptr)
		{
			return;
		}
		porder.emplace_back(root->val);
		order(porder, root->left);
		order(porder, root->right);
	}
public:
	vector<int> preorder(TreeNode* root)
	{
		if (root == nullptr)
		{
			return vector<int> {};
		}
		vector<int> porder;
		order(porder, root);
		return porder;
	}
};


/*
中序（左-根-右）遍历
*/
class inorderSolution {
private:
	void order(vector<int>& porder, TreeNode* root)
	{
		if (root == nullptr)
		{
			return;
		}
		order(porder, root->left);
		porder.emplace_back(root->val);
		order(porder, root->right);
	}
public:
	vector<int> inorder(TreeNode* root)
	{
		if (root == nullptr)
		{
			return vector<int> {};
		}
		vector<int> porder;
		order(porder, root);
		return porder;
	}
};

/*
后序（左-右-根）遍历
*/
class postorderSolution {
private:
	void order(vector<int>& porder, TreeNode* root)
	{
		if (root == nullptr)
		{
			return;
		}
		order(porder, root->left);
		order(porder, root->right);
		porder.emplace_back(root->val);
	}
public:
	vector<int> postorder(TreeNode* root)
	{
		if (root == nullptr)
		{
			return vector<int> {};
		}
		vector<int> porder;
		order(porder, root);
		return porder;
	}
};



/*
从前序（根-左-右）与中序遍历（左-根-右）序列构造二叉树
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/cong-qian-xu-yu-zhong-xu-bian-li-xu-lie-gou-zao-9/
来源：力扣（LeetCode）
*/

/*
方法一：递归
时间复杂度： O(n),n为数结点总数
空间复杂度： O(n),哈希表O(n) 递归栈空间O(h) h < n
*/

class buildTreeFromPreAndInorderSolution1 {
private:
	unordered_map<int, int> index;
public:
	TreeNode* build(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right)
	{
		ios::sync_with_stdio(false);
		if (preorder_left > preorder_right)
		{
			return nullptr;
		}

		//前序遍历第一个结点就是根节点
		int preorder_root = preorder[preorder_left];
		int inorder_root = index[preorder_root];

		//左子树结点个数
		int size_left_sub = inorder_root - inorder_left;

		TreeNode* root = new TreeNode(preorder_root);

		//递归构造左子树
		root->left = build(preorder, inorder, preorder_left + 1, preorder_left + size_left_sub, inorder_left, inorder_root - 1);
		//递归构造右子树
		root->right = build(preorder, inorder, preorder_left + size_left_sub + 1, preorder_right, inorder_root + 1, inorder_right);
		return root;
	}


	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		if (preorder.empty() || inorder.empty())
		{
			return nullptr;
		}

		int nsize = (int)inorder.size();

		//构造哈希表快速定位根结点位置
		for (int i = 0; i < nsize; i++)
		{
			index[inorder[i]] = i;
		}
		return build(preorder, inorder, 0, nsize - 1, 0, nsize - 1);
	}
};


/*
判断是不是镜像二叉树
方法：递归
题目链接：https://leetcode-cn.com/problems/symmetric-tree
来源：力扣（LeetCode）
*/

class isSymmetricSolution {
	bool judge(TreeNode *r1, TreeNode *r2)
	{
		if (r1 == NULL && r2 == NULL)
		{
			return true;
		}

		if (r1 == NULL || r2 == NULL)
		{
			return false;
		}

		if (r1->val != r2->val)
		{
			return false;
		}

		return judge(r1->left, r2->right) && judge(r1->right, r2->left);
	}
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
		{
			return true;
		}

		return judge(root->left, root->right);
	}
};


/*
从先序遍历还原二叉树
题目链接：https://leetcode-cn.com/problems/recover-a-tree-from-preorder-traversal/
来源：力扣（LeetCode）
*/

class recoverATreeFromPreorderTraversalSolution {
private:
	bool isNum(const char c)
	{
		if ('0' <= c && c <= '9')
		{
			return true;
		}
		return false;
	}

	int getNum(const string &s, int &i)
	{
		int ans = 0;
		int ssize = s.size();

		while (i < ssize && isNum(s[i]))
		{
			ans *= 10;
			ans += s[i] - '0';
			i++;
		}
		return ans;
	}

public:
	TreeNode* recoverFromPreorder(string S) {
		int ssize = S.size();
		stack<TreeNode*> s;

		int pos = 0;
		while (pos < ssize)
		{
			int level = 0;
			while (S[pos] == '-')
			{
				level++;
				pos++;
			}
			int value = getNum(S, pos);

			TreeNode *node = new TreeNode(value);

			if (level == s.size())
			{
				if (!s.empty())
				{
					s.top()->left = node;
				}
			}
			else
			{
				while (level != s.size())
				{
					s.pop();
				}
				s.top()->right = node;
			}
			s.push(node);
		}
		while (s.size() > 1)
		{
			s.pop();
		}
		return s.top();
	}
};
